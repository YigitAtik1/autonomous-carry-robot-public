% Reconstructed from 2021 thesis Appendix 1; untested; PDF formatting may have introduced defects.
load exampleMaps.mat %load example map
%map = occupanc
MATRIX = readmatrix('MapMatrix.xls');
refMap = occupancyMap (MATRIX);
%refMap = binaryOccupancyMap(simpleMap,1); %reference map specs and resulotion
refFigure = figure('Name','SimpleMap'); % name the figure
show(refMap); % show the refMap

[mapdimx,mapdimy] = size(MATRIX); %taking the sizes of the refMap
mapx = binaryOccupancyMap(mapdimy,mapdimx,10); %creating new map with the same indices nut 10 time more resulotion
mapFigure = figure('Name','Unknown Map'); % name the figure
show(mapx); %showing the created map

diffDrive     = differentialDriveKinematics("VehicleInputs","VehicleSpeedHeadingRate");%creating differential Drive kinematic model

controller      =     controllerPurePursuit('DesiredLinearVelocity',2,'MaxAngularVelocity',3);%pursuit controller to follow a desired path

sensor = rangeSensor;%creating a senssor
sensor.Range = [0,8];%choosing 10 meters as max length of measurement

%path = [4 6; 6.5 12.5; 4 22; 12 14; 22 22; 16 12; 20 10; 14 6; 22 3];%path to drive on to gather recordings of range sensor measurements
%START
%load exampleMaps.mat
map = occupancyMap (MATRIX);
%show(map)
robotRadius = 0.2;
mapInflated = copy(map);
inflate(mapInflated,robotRadius);
%show(mapInflated)
prm = mobileRobotPRM;
prm.Map = mapInflated;
prm.NumNodes = 120;
prm.ConnectionDistance = 5;
startLocation = [5 4];
endLocation = [21 4];
path = findpath(prm, startLocation, endLocation)
%show(prm)
%END

%plotting the path
figure(refFigure);

hold on
plot(path(:,1),path(:,2), 'o-');% no idea
hold off
%
controller.Waypoints = path;%pointing the path via pursuit controller

%Set the initial pose and final goal location based on the path.
%Create global variables for storing the current pose and an index for tracking the iterations.
initPose = [path(1,1) path(1,2), pi/2];%starting point on grid
goal = [path(end,1) path(end,2)]';%finishing point on grid
poses(:,1) = initPose'; % no idea but assuming is an incrementation

%%example loop for robot control

exampleHelperDiffDriveCtrl(diffDrive,controller,initPose,goal,refMap,mapx,refFigure,mapFigure,sensor)
%1-Scan reference map via range sensor readings simulates normal range readings for driving in an unknown environment.
%2-update the map via readings
%3-Getting control inputs from the Inputcontroller to drive to next waypoint
%4-Calculate derivative of motion of robot via control commands
%5-Increment the position

function exampleHelperDiffDriveCtrl(diffDrive,ppControl,initPose,goal,map1,map2,fig1,fig2,lidar)
sampleTime = 0.05;         % Sample time [s]
t = 0:sampleTime:100;      % Time array
poses = zeros(3,numel(t)); % Pose matrix (what is numel)
poses(:,1) = initPose';

% Set iteration rate
r = rateControl(1/sampleTime);

% Get the axes from the figures
ax1 = fig1.CurrentAxes;
ax2 = fig2.CurrentAxes;

for idx = 1:numel(t)
position = poses(:,idx)';
currPose = position(1:2);

% End if pathfollowing is vehicle has reached goal position within tolerance of 0.2m
dist = norm(goal'-currPose);
if (dist < .2)
disp("Goal position reached")
break;
end

% Update map by taking sensor measurements
figure(2)
%%

[ranges, angles] = lidar(position, map1);
scan = lidarScan(ranges,angles);
validScan = removeInvalidData(scan,'RangeLimits',[0,lidar.Range(2)]);
insertRay(map2,position,validScan,lidar.Range(2));
show(map2);

% Run the Pure Pursuit controller and convert the output to wheel speeds
[vRef,wRef] = ppControl(poses(:,idx));

% Perform forward discrete integration step
vel = derivative(diffDrive, poses(:,idx), [vRef wRef]);
poses(:,idx+1) = poses(:,idx) + vel*sampleTime;

% Update visualization
plotTrvec = [poses(1:2, idx+1); 0];
plotRot = axang2quat([0 0 1 poses(3, idx+1)]);

% Delete image of the last robot to prevent displaying multiple robots
if idx > 1
items = get(ax1, 'Children');
delete(items(1));
end

%plot robot onto known map
plotTransforms(plotTrvec', plotRot, 'MeshFilePath', 'groundvehicle.stl', 'View', '2D', 'FrameSize', 1, 'Parent', ax1);
%plot robot on new map
plotTransforms(plotTrvec', plotRot, 'MeshFilePath', 'groundvehicle.stl', 'View', '2D', 'FrameSize', 1, 'Parent', ax2);

% waiting to iterate at the proper rate
waitfor(r);
end
end
