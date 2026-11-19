% Reconstructed from 2021 thesis Appendix 1; untested; PDF formatting may have introduced defects.
load('offlineSlamData.mat'); %laser scans downloading meaning the measurements here is ready to use

%Using: Jackal Robot from Clearpath Robotics equipped with SICK TIM 511
%laser scanner waitfor0 m)

maxLidarRange = 8;%adjusting to 8 meters for presicion
mapResolution = 20;%20 cells per cell resulotion
slamAlg = lidarSLAM(mapResolution, maxLidarRange); %slam algorithm is fetched(this algorithm doesn't belong to us)

%The following loop closure parameters are set empirically.
%Using a higher loop closure threshold helps reject false positives in the loop closure identification process.
%However, keep in mind that a high-score match may still be a bad match.
%For example, scans collected in an environment that has similar or repeated features are more likely to produce false positives.
%Using a higher loop closure search radius allows the algorithm to search a wider range of the map around the current pose estimate for loop closures.

slamAlg.LoopClosureThreshold = 210;
slamAlg.LoopClosureSearchRadius = 8;

for i=1:10%incrementally add scans to slam object. First 10 scans are added for testing the algorithm
[isScanAccepted, loopClosureInfo, optimizationInfo] = addScan(slamAlg, scans{i});
if isScanAccepted
fprintf('Added scan %d \n', i);
end
end

figure;
show(slamAlg);%plotting the draft with 10 scans added
title({'Map of the Environment','Pose Graph for Initial 10 Scans'});

firstTimeLCDetected = false;

figure;
for i=10:length(scans)% continue adding scans simoltaneousely. Closures are being deteced
% automatically while robot moves
[isScanAccepted, loopClosureInfo, optimizationInfo] = addScan(slamAlg, scans{i});
if ~isScanAccepted
continue;
end
% visualize the first detected loop closure, if you want to see the
% complete map building process, remove the if condition below
if optimizationInfo.IsPerformed && ~firstTimeLCDetected %optimizationInfo has a field,
% IsPerformed (when optimization occurs)
show(slamAlg, 'Poses', 'off');

hold on;
show(slamAlg.PoseGraph);
hold off;
firstTimeLCDetected = true;
drawnow
end
end
%Plot the scans and poses whenever a loop closure is identified and verify the results visually.
%This plot shows overlaid scans and an optimized pose graph for the first loop closure. A loop closure edge is added as a red link.
title('First loop closure');

figure
show(slamAlg);%plotting the final built map after all scans are overlayed
title({'Final Built Map of the Environment', 'Trajectory of the Robot'});

%creating an occupancy map from the scans
[scans, optimizedPoses] = scansAndPoses(slamAlg);
map = buildMap(scans, optimizedPoses, mapResolution, maxLidarRange);
figure;
show(map);
hold on
show(slamAlg.PoseGraph, 'IDs', 'off');
hold off
title('Occupancy Grid Map Built Using Lidar SLAM');
