#ifndef VALUE_H
#define VALUE_H

#define WINDOWSCOLOR 255,255,255,255
#define WALLCOLOR 0.8789,0.55078,0.2
#define TRACECOLOR 0.7,0.1,0.8
#define PATHCOLOR 0.235,0.523,0.219
#define EXITCOLOR 0.6,0.3,0.2
#define PLAYCOLOR 0,0,0

std::string ProgramName = "Maze by 2016060107001";

#include "Maze.h"

Maze::maze mm;

LL ShowAreaBlockX = 20, ShowAreaBlockY = 20;
LL Rectlen=50, WindowsWidth=Rectlen*ShowAreaBlockX, Windowsheight=Rectlen*ShowAreaBlockY;
LL SX=0,SY=0;

std::pair<LL, LL>nowpos, endpos;

bool showtrace = false, showpath = false, win=false;

#endif // !VALUE_H
