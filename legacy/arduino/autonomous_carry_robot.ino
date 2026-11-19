//#include <string>
const int left_backward = 7;
const int left_forward = 6;
const int right_backward = 9;
const int right_forward = 8;
using namespace std;
#define earthSizeX 10
#define earthSizeY 10
#define tooMuchDistance (earthSizeX+earthSizeY)*2
#define gridSizeX 9
#define gridSizeY 9
#define emptyCell -5
//#define k 9

int earth [earthSizeX][earthSizeY] =
{{1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
 {1, 1, 1, 1, -5, 1, 1, 1, 1, 1},
 {1, 1, 1, 1, 1, -5, 1, 1, 1, 1},
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
 {1, 1, 1, 1, 1, -5, 1, 1, 1, 1},
 {1, 1, 1, 1, 1, 1, -5, 1, 1, 1},
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1},
 {1, 1, 1, 1, 1, 1, 1, 1, 1, 1}
};
int oldCurx;
int oldCury;
int curAngle = 0;
int desAngle = 0;
int r;
int curx = 4;
int cury = 4;
int startx = 4;
int starty = 4;
int goalx = 7;
int goaly = 7;
int curVal = 2;
int subMap[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int ctemp[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int rtemp[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int ctempy[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

int rtempx[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
int curMinIndex = 0;
int subIndexLimit = 8;

void setup() {
  pinMode(left_backward, OUTPUT);            // sets the digital pin as output
  pinMode(left_forward, OUTPUT);
  pinMode(right_backward, OUTPUT);             // sets the digital pin as output
  pinMode(right_forward, OUTPUT);
  Serial.begin(9600);
  //Serial.println("--- Start Serial Monitor SEND_RCVE ---");
  //Serial.println("Type in Box Above , .");
  //Serial.println("(Decimal)(Hex)(Character)");
  //Serial.println();
  earth[curx][cury] = -1;
  //findMinDistancedMaxPotentialIndex();
  //filltheMap();
}

void filltheMap() {
 // put your main code here, to run repeatedly:
 //while (~(curx == goalx && cury == goaly))

 if (curx == gridSizeX && cury == gridSizeY) {
   if (earth[curx - 1][cury - 1] == 1) {
     earth[curx - 1][cury - 1] = curVal;
   }
   if (earth[curx][cury - 1] == 1) {
     earth[curx][cury - 1] = curVal;
   }

  if (earth[curx - 1][cury] == 1) {
    earth[curx - 1][cury] = curVal;
  }
 }
 else if (curx == gridSizeX && cury == 0) {
   if (earth[curx - 1][cury] == 1) {
     earth[curx - 1][cury] = curVal;
   }
   if (earth[curx - 1][cury + 1] == 1) {
     earth[curx - 1][cury + 1] = curVal;
   }
   if (earth[curx][cury + 1] == 1) {
     earth[curx][cury + 1] = curVal;
   }
 }
 else if (curx == gridSizeX && cury > 0) {

 if (earth[curx - 1][cury - 1] == 1) {
   earth[curx - 1][cury - 1] = curVal;
 }
 if (earth[curx][cury - 1] == 1) {
   earth[curx][cury - 1] = curVal;
 }
 if (earth[curx - 1][cury] == 1) {
   earth[curx - 1][cury] = curVal;
 }
 if (earth[curx - 1][cury + 1] == 1) {
   earth[curx - 1][cury + 1] = curVal;
 }
 if (earth[curx][cury + 1] == 1) {
   earth[curx][cury + 1] = curVal;
 }
}
else if (curx == 0 && cury == gridSizeY) {
  if (earth[curx][cury - 1] == 1) {
    earth[curx][cury - 1] = curVal;
  }
  if (earth[curx + 1][cury - 1] == 1) {
    earth[curx + 1][cury - 1] = curVal;
  }
  if (earth[curx + 1][cury] == 1) {
    earth[curx + 1][cury] = curVal;
  }
}
else if (curx > 0 && cury == gridSizeY) {
  if (earth[curx - 1][cury - 1] == 1) {
    earth[curx - 1][cury - 1] = curVal;
  }
  if (earth[curx][cury - 1] == 1) {
    earth[curx][cury - 1] = curVal;
  }
  if (earth[curx - 1][cury] == 1) {
    earth[curx - 1][cury] = curVal;
  }
  if (earth[curx + 1][cury ] == 1) {
    earth[curx + 1][cury ] = curVal;
  }
  if (earth[curx + 1][cury - 1] == 1) {
    earth[curx + 1][cury - 1] = curVal;
  }
}
else if (curx == 0 && cury == 0) {
  if (earth[curx + 1][cury] == 1) {
    earth[curx + 1][cury] = curVal;

 }
 if (earth[curx][cury + 1] == 1) {
   earth[curx][cury + 1] = curVal;
 }
 if (earth[curx + 1][cury + 1] == 1) {
   earth[curx + 1][cury + 1] = curVal;
 }
}
else if (curx > 0 && cury > 0) {
  if (earth[curx - 1][cury - 1] == 1) {
    earth[curx - 1][cury - 1] = curVal;
  }
  if (earth[curx][cury - 1] == 1) {
    earth[curx][cury - 1] = curVal;
  }
  if (earth[curx + 1][cury - 1] == 1) {
    earth[curx + 1][cury - 1] = curVal;
  }
  if (earth[curx - 1][cury] == 1) {
    earth[curx - 1][cury] = curVal;
  }
  if (earth[curx + 1][cury] == 1) {
    earth[curx + 1][cury] = curVal;
  }
  if (earth[curx - 1][cury + 1] == 1) {
    earth[curx - 1][cury + 1] = curVal;
  }
  if (earth[curx][cury + 1] == 1) {
    earth[curx][cury + 1] = curVal;
  }
  if (earth[curx + 1][cury + 1] == 1) {
    earth[curx + 1][cury + 1] = curVal;
  }
}
else if (curx == 0 && cury > 0) { //(curx==0 && cury>0)
  if (earth[curx][cury - 1] == 1) {
    earth[curx][cury - 1] = curVal;
  }
  if (earth[curx + 1][cury - 1] == 1) { //==1
    earth[curx + 1][cury - 1] = curVal;
  }
  if (earth[curx + 1][cury] == 1) {
    earth[curx + 1][cury] = curVal;
  }
  if (earth[curx][cury + 1] == 1) {
    earth[curx][cury + 1] = curVal;
  }

    if (earth[curx + 1][cury + 1] == 1) {
      earth[curx + 1][cury + 1] = curVal;
    }
}
else if (cury == 0 && curx > 0) {
  if (earth[curx - 1][cury] == 1) {
    earth[curx - 1][cury] = curVal;
  }
  if (earth[curx + 1][cury] == 1) {
    earth[curx + 1][cury] = curVal;
  }
  if (earth[curx - 1][cury + 1] == 1) {
    earth[curx - 1][cury + 1] = curVal;
  }
  if (earth[curx][cury + 1] == 1) {
    earth[curx][cury + 1] = curVal;
  }

    if (earth[curx + 1][cury + 1] == 1) {
      earth[curx + 1][cury + 1] = curVal;
    }
    if (earth[curx - 1][cury - 1] == 1) {
      earth[curx - 1][cury - 1] = curVal;
    }
    if (earth[curx][cury - 1] == 1) {
      earth[curx][cury - 1] = curVal;
    }
    if (earth[curx + 1][cury - 1] == 1) {
      earth[curx + 1][cury - 1] = curVal;
    }
    if (earth[curx - 1][cury] == 1) {
      earth[curx - 1][cury] = curVal;
    }
    if (earth[curx + 1][cury] == 1) {
      earth[curx + 1][cury] = curVal;
    }
    if (earth[curx - 1][cury + 1] == 1) {
      earth[curx - 1][cury + 1] = curVal;
    }
    if (earth[curx][cury + 1] == 1) {
      earth[curx][cury + 1] = curVal;
    }
    if (earth[curx + 1][cury + 1] == 1) {
      earth[curx + 1][cury + 1] = curVal;
    }

}

 curVal++;
 // findMinDistancedMaxPotentialIndex();

 //curx = rtempx[curMinIndex];//newcurx = rtempx[curMinIndex]
 // cury = ctempy[curMinIndex];

 //cout << curx << endl;
 //cout << cury << endl;
}
void loop() {
  oldCurx = curx;//şuan bulunduüum index
  oldCury = cury;
  // aimed curx and cury result of the wavefront


 if (curx == goalx && cury == goaly) {
   //Serial.println("dfd");
 }
 else {

  filltheMap();
  findMinDistancedMaxPotentialIndex();

  // if (~(curx == goalx && cury == goaly)) {
  for (int i = 0; i < 10; i++) {
    for (int j = 0; j < 10; j++) {

    // Serial.print(earth[i][j]);
    // Serial.print("\t");

    }
   // Serial.println();
  }
  curx = rtempx[curMinIndex];//newcurx = rtempx[curMinIndex]
  cury = ctempy[curMinIndex];
  earth[curx][cury] = -1;
   motorControlFunction();//motor control fonksüyon çağırma


  // }
 // for (int i = 0; i < 10; i++) {
   // for (int j = 0; j < 10; j++) {
      //Serial.print(earth[i][j]);
      //Serial.print("\t");
   // }
   // Serial.println();

 // }

 // Serial.println("curvalues");
 // Serial.print(curx);
  //Serial.print("\t");
  //Serial.print(cury);
  //Serial.println();


 }

}
/*void createSubMap()
  {
  int tempMap[9];
  if (curx == gridSizeX && cury == gridSizeY) { //grid indisleri değiştirilebilir olmalı!!
    int tempMap[9] = {earth[curx - 1][cury - 1], earth[curx][cury - 1], -5, earth[curx -
1][cury], earth[curx][cury], -5, -5, -5, -5}; // some if conditions and various tempMaps
  }
  else if (curx == 9 && cury == 0) {
    int tempMap[9] = { -5, earth[curx][cury - 1], earth[curx + 1][cury - 1], -5,
earth[curx][cury], earth[curx + 1][cury], -5, -5, -5}; // some if conditions and various
tempMaps
  }
  else if (curx == 9 && cury > 0) {
    int tempMap[9] = {earth[curx - 1][cury - 1], earth[curx][cury - 1], earth[curx + 1][cury -
1], earth[curx - 1][cury], earth[curx][cury], earth[curx + 1][cury], -5, -5, -5}; // some if
conditions and various tempMaps
  }
  else if (curx == 0 && cury == 9) {
    int tempMap[9] = { -5, -5, -5, earth[curx - 1][cury], earth[curx][cury], -5, earth[curx -
1][cury + 1], earth[curx][cury + 1], -5}; // some if conditions and various tempMaps
  }
  else if (curx > 0 && cury == 9) {
    int tempMap[9] = {earth[curx - 1][cury - 1], earth[curx][cury - 1], -5, earth[curx *
1][cury], earth[curx][cury], -5, earth[curx - 1][cury + 1], earth[curx][cury + 1], -5}; // once
tempMap is completed, carry everything to global subMap
  }
  else if (curx == 0 && cury == 0) {
    int tempMap[9] = { -5, -5, -5, -5, earth[curx][cury], earth[curx + 1][cury], -5,
earth[curx][cury + 1], earth[curx + 1][cury + 1]}; //-5 ler başta define edilecek her seferinde
memorye bakma
  }
  else if (curx == 0 && cury > 0) {

   int tempMap[9] = { -5, -5, -5, earth[curx][cury - 1], earth[curx][cury], earth[curx][cury +
1], earth[curx + 1][cury - 1], earth[curx + 1][cury], earth[curx + 1][cury + 1]};
 }
 else if (curx > 0 && cury == 0) {
   int tempMap [9] = { -5, earth[curx][cury - 1], earth[curx + 1][cury - 1], -5,
earth[curx][cury], earth[curx + 1][cury], -5, earth[curx][cury + 1], earth[curx + 1][cury +
1]};
 }
 else if (curx>0 && cury>0){
   int tempMap[9] = {earth[curx - 1][cury - 1], earth[curx][cury - 1], earth[curx + 1][cury -
1], earth[curx - 1][cury], earth[curx][cury], earth[curx + 1][cury], earth[curx - 1][cury + 1],
earth[curx][cury + 1], earth[curx + 1][cury + 1]};
 }
 else{
   int tempMap[9] = {earth[curx - 1][cury - 1], earth[curx][cury - 1], earth[curx + 1][cury -
1], earth[curx - 1][cury], earth[curx][cury], earth[curx + 1][cury], earth[curx - 1][cury + 1],
earth[curx][cury + 1], earth[curx + 1][cury + 1]};
   // just to be sure temp map is exist
 }
 for (int i = 0; i < 9; i++)
 {
   subMap[i] = tempMap[i];
 }

  }
*/
void fillTempMap(int tempTempMap[], int tempIfMap[])
{
  for (int i = 0; i < 9; i++)
  {
    tempTempMap[i] = tempIfMap[i];
  }

}

void createSubMap()
{
  int tempMap [9] = { -5, -5, -5, -5, -5, -5, -5, -5, -5}; // some if conditions and various
tempMaps

  if (curx == gridSizeX && cury == gridSizeY) { //grid indisleri değiştirilebilir olmalı!!
    int tempIfMap[9] = {earth[curx - 1][cury - 1], earth[curx - 1][cury ], -5, earth[curx][cury
- 1], earth[curx][cury], -5, -5, -5, -5}; // some if conditions and various tempMaps
    fillTempMap(tempMap, tempIfMap);
  }
  else if (curx == 9 && cury == 0) {
    int tempIfMap[9] = { -5, earth[curx - 1][cury], earth[curx - 1][cury + 1], -5,

earth[curx][cury], earth[curx ][cury + 1], -5, -5, -5}; // some if conditions and various
tempMaps
    fillTempMap(tempMap, tempIfMap);
  }

  else if (curx == 9 && cury > 0) {
    int tempIfMap[9] = {earth[curx - 1][cury - 1], earth[curx - 1][cury], earth[curx - 1][cury
+ 1], earth[curx ][cury - 1], earth[curx][cury], earth[curx ][cury + 1], -5, -5, -5}; // some if
conditions and various tempMaps
    fillTempMap(tempMap, tempIfMap);
  }
  else if (curx == 0 && cury == 9) {
    int tempIfMap[9] = { -5, -5, -5, earth[curx ][cury - 1], earth[curx][cury], -5, earth[curx +
1][cury - 1], earth[curx + 1][cury ], -5}; // some if conditions and various tempMaps
    fillTempMap(tempMap, tempIfMap);
  }
  else if (curx > 0 && cury == 9) {
    int tempIfMap[9] = {earth[curx - 1][cury - 1], earth[curx - 1][cury], -5, earth[curx ][cury
- 1], earth[curx][cury], -5, earth[curx + 1][cury - 1], earth[curx + 1][cury ], -5}; // once
tempMap is completed, carry everything to global subMap
    fillTempMap(tempMap, tempIfMap);
  }
  else if (curx == 0 && cury == 0) {
    int tempIfMap[9] = { -5, -5, -5, -5, earth[curx][cury], earth[curx ][cury + 1], -5,
earth[curx + 1][cury ], earth[curx + 1][cury + 1]}; //-5 ler başta define edilecek her
seferinde memorye bakma
    fillTempMap(tempMap, tempIfMap);
  }
  else if (curx == 0 && cury > 0) {
    int tempIfMap[9] = { -5, -5, -5, earth[curx ][cury - 1], earth[curx][cury], earth[curx ][cury
+ 1], earth[curx + 1][cury - 1], earth[curx + 1][cury ], earth[curx + 1][cury + 1]};
    fillTempMap(tempMap, tempIfMap);
  }
  else if (curx > 0 && cury == 0) {
    int tempIfMap [9] = { -5, earth[curx - 1][cury], earth[curx - 1][cury + 1], -5,
earth[curx][cury], earth[curx ][cury + 1], -5, earth[curx + 1][cury ], earth[curx + 1][cury +
1]};
    fillTempMap(tempMap, tempIfMap);
  }
  else if (curx > 0 && cury > 0) {
    int tempIfMap[9] = {earth[curx - 1][cury - 1], earth[curx - 1][cury], earth[curx - 1][cury
+ 1], earth[curx ][cury - 1], earth[curx][cury], earth[curx ][cury + 1], earth[curx + 1][cury -
1], earth[curx + 1][cury ], earth[curx + 1][cury + 1]};
    fillTempMap(tempMap, tempIfMap);
  }
  //Serial.println ("subas");

    for (int i = 0; i < 9; i++)
    {
      subMap[i] = tempMap[i];
      //cout<<subMap[i]<<"\t"<<endl;
    // Serial.println (subMap[i]);


    }
    //Serial.println ("subitis");

}
void convertIndexesOfSubToEarth(int subMaxIndArr[])
{
  for (int i = 0; i < 9; i++)
  {
    if (i <= subIndexLimit)
    {

         ctemp[i] = subMaxIndArr[i] % 3;
         rtemp[i] = (subMaxIndArr[i] - ctemp[i]) / 3;
        }
        else {
          rtemp[i] = earthSizeX * 10;
          ctemp[i] = earthSizeY * 10;
        }
    }
}

void compansateShiftOfEarthIndexes()
{
  int xshift = 0;
  int yshift = 0;


    xshift = -1 + curx;
    yshift = -1 + cury;

    /* else if (curx == gridSizeX && cury == 0) {
      xshift = -1 + curx;
      yshift = cury;
     }
     else if (curx == gridSizeX && cury > 0) {
      xshift = -1 + curx;
      yshift = -1 + cury;
     }
     else if (curx == 0 && cury == gridSizeY) {
      xshift = -1 + curx;

       yshift = -1 + cury;
      }
      else if (curx > 0 && cury == gridSizeY) {
       xshift = -1 + curx;
       yshift = -1 + cury;
      }
      else if (curx == 0 && cury == 0) {
       xshift = -1 + curx;
       yshift = cury;
      }
      else if (curx == 0 && cury > 0) {
       xshift = curx;
       yshift = -1 + cury;
      }
      else if (curx > 0 && cury == 0) {
       xshift = -1 + curx;
       yshift = cury;
      }
      else if (curx > 0 && cury > 0) {
       xshift = -1 + curx;
       yshift = -1 + cury;
      }
    */
    // some if conditions and various tempMaps
    // some if conditions and various tempMaps
    // some if conditions and various tempMaps

    for (int i = 0; i < 9; i++)
    {
      rtempx[i] = rtemp[i] + xshift;
      ctempy[i] = ctemp[i] + yshift;
    }
}


void findMinDistantIndex(int distArr[])
{
  int minVal = tooMuchDistance;
  for (int i = 0; i < 9; i++)// muhtemel 0 yerine 1 yazılan yer düzeltildi
  {
    if (distArr[i] < minVal)
    {
      minVal = distArr[i];
    }
  }

    for (int i = 0; i < 9; i++)
    {
      if (distArr[i] == minVal)
      {
        curMinIndex = i;
        break;
      }
    }

}

void calculateDistancesOfMaxNeighbourAndReturnMinDistantIndex(int limitInd)
{
  int distArr[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};

    for (int i = 0; i < 9; i++)
    {
      if (i <= limitInd)
      {
        distArr[i] = abs(rtempx[i] - goalx) + abs(ctempy[i] - goaly);
      }
      else
      {
        distArr[i] = tooMuchDistance;
      }
    }
    for (int i = 0; i < 9; i++)
    {

      //cout<<subMap[i]<<"\t"<<endl;
      //Serial.print (distArr[i]);
      //Serial.print("\t");
      //Serial.print(rtempx[i]);
     // Serial.print("\t");
      //Serial.print(ctempy[i]);
     //Serial.println();
    }
    findMinDistantIndex(distArr);

}


void findMinDistancedMaxPotentialIndex()
{
  createSubMap();

    int maxVal = subMap[0];

 int maxInd[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
 for (int i = 1; i < 9; i++)
 {
   if (subMap[i] > maxVal)
   {
     maxVal = subMap[i];
   }
 }
 int j = 0;
 for (int i = 0; i < 9; i++)
 {
   if (subMap[i] == maxVal)
   {
     maxInd[j] = i;
     j++;
   }
 }
 j--;
 subIndexLimit = j;

 convertIndexesOfSubToEarth(maxInd);
 compansateShiftOfEarthIndexes();

 calculateDistancesOfMaxNeighbourAndReturnMinDistantIndex(j);

}
void motorControlFunction() {
  //dirx = curx - oldCurx;
  //diry = cury - oldCury;
  //curAngle = 0; //aşağı bakarken current angle 0 kabul edildi
  //curAngle başta 0 olarak tanımlandı her conditionın sonunda yenileniyor


 //curAngle=curAngle%360;
 //Left-up motion
 if ((curx == oldCurx - 1) && (cury == oldCury - 1)) { //dirx diry hesaplamak yerine
condition koyduk esk, ve yeni indisleri karşılaştırarak yön tayini

     desAngle = -135;
 }

 //Left motion
 if ((curx == oldCurx) && (cury == oldCury - 1)) {
   desAngle = -90;
 }

//Left- down motion
if ((curx == oldCurx + 1) && (cury == oldCury - 1)) {
  desAngle = -45;
}
//Up motion
if ((curx == oldCurx - 1) && (cury == oldCury)) {
  desAngle = 180;

}

//Down motion
if ((curx == oldCurx + 1) && (cury == oldCury)) {

    desAngle = 0;
}

// Right-up motion
if ((curx == oldCurx - 1) && (cury == oldCury + 1)) {
  desAngle = 135;

}

//Right motion
if ((curx == oldCurx ) && (cury == oldCury + 1)) {
  desAngle = 90;

}
//Right-down motion
if ((curx == oldCurx + 1) && (cury == oldCury + 1))
{
  desAngle = 45;


}

 //Serial.println(oldCurx);
// Serial.println(curx);
 //Serial.println(oldCury);
 //Serial.println(cury);
// Serial.println("desAngle");
   //Serial.println(desAngle);

r = (desAngle - curAngle) / 45 ;

if (r < 0) { //r negative ise
  //r yi pozitif yaptık doru doğru döndürmek için
  for (int i = 0; i < abs(r); i++) { // r sayısı kadar fonksüyon çevir

      negative45Degrees();
      }
    }
    else if (r > 0) { //r positive ise
      for (int i = 0; i < abs(r); i++) {
        positive45Degrees();//rotasyon tamamlandı
      }
    }
      if (oldCurx == goalx && oldCury == goaly) {
      }
      else{
    forwardDrive();
      }
    curAngle = desAngle;

}

void forwardDrive() {
 Serial.println("forward");
 digitalWrite(left_forward, HIGH);
 digitalWrite(right_forward, HIGH);
 delay(1000);// 1 cell forward
 digitalWrite(left_forward, LOW);
 digitalWrite(right_forward, LOW);
 delay(500);


}
void positive45Degrees() {
  Serial.println("Pos45");

    digitalWrite(right_forward, HIGH);
    //digitalWrite(left_backward, HIGH);
    delay(800);//for 45 degrees
    digitalWrite(right_forward, LOW);
    digitalWrite(left_backward, LOW);
    delay(500);
}
void negative45Degrees() {
  Serial.println("Neg45");
  digitalWrite(left_forward, HIGH);
  //digitalWrite(right_backward, HIGH);
  delay(800);//45 degrees
  digitalWrite(left_forward, LOW);
  digitalWrite(right_backward, LOW);
  delay(500);

}
