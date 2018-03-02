//
// Created by a on 12/25/17.
//

#ifndef LIFE_VALUE_H
#define LIFE_VALUE_H

#define BACKGROUNDCOLOR 1,1,1,1
#define POINTCOLOR  0.6,0.1,0.1
#define LINECOLOR   0.12,0.3,0.7

int WindowHeight=1000,WindowWidth=1000;
int pixelx=50,pixely=50;
int pixelsize=1;
int blocklen=WindowWidth/pixelx;
bool temp[1000][1000],m[1000][1000];
bool p=1;
unsigned int sleeptime=400000;

#endif //LIFE_VALUE_H
