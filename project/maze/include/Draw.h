#ifndef DRAW_H
#define DRAW_H

#include "Maze.h"

void DrawMap();
void DrawPlayer();
void DrawPath();
void DrawTrace();
void DrawExit();

void DrawFun()
{
	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(0, WindowsWidth, 0, Windowsheight);
	glClearColor(WINDOWSCOLOR);
	glClear(GL_COLOR_BUFFER_BIT);
	
	DrawMap();
	DrawPlayer();
	if (showpath)	DrawPath();
	if (showtrace)	DrawTrace();
	DrawExit();

	glutSwapBuffers();
}

void KeyBordFun(unsigned char cmd,int x,int y)
{
	switch (cmd)
	{
	case 'w':
	{
		mm.move(0, 1);
		break;
	}
	case 'a':
	{
		mm.move(-1, 0);
		break;
	}
	case 's':
	{
		mm.move(0, -1);
		break;
	}
	case 'd':
	{
		mm.move(1, 0);
		break;
	}
	case 'p':
	{
		showpath = !showpath;
		break;
	}
	case 't':
	{
		showtrace = !showtrace;
		break;
	}
	case 'n':
	{
		init();
		break;
	}
	case 'e':
	{
		exit(1);
	}
	}
}

void ScaleFun(int x,int y)
{
	LL len = std::min(x, y);
	Rectlen = len / ShowAreaBlockX;
	WindowsWidth = Rectlen*ShowAreaBlockX;
	Windowsheight = Rectlen*ShowAreaBlockY;
}

void IdleFun()
{
	glutPostRedisplay();
}

void DrawRec(LL x, LL y, LL len)
{
	glBegin(GL_POLYGON);
	
	glVertex2d(x, y);
	glVertex2d(x + len, y);
	glVertex2d(x + len, y + len);
	glVertex2d(x, y + len);
	
	glEnd();
}

void DrawMap()
{
	int **p;
	LL i, j, x1,y1;
	p = new int*[ShowAreaBlockY];
	for (i = 0; i < ShowAreaBlockY; i++)	p[i] = new int[ShowAreaBlockX];
	mm.getrect(ShowAreaBlockX, ShowAreaBlockY, p);

	glColor3d(WALLCOLOR);
	for (i = 0; i < ShowAreaBlockX; i++)
	for (j = 0; j < ShowAreaBlockY; j++)
		if (p[i][j])
		{
			x1 = i*Rectlen, y1 = j*Rectlen;
			DrawRec(x1, y1, Rectlen);
		}
}

void DrawPlayer()
{
	LL x1,y1;;
	glColor3d(PLAYCOLOR);
	x1 = nowpos.first - SX,x1=Rectlen*x1+Rectlen/3;
	y1 = nowpos.second - SY,y1=Rectlen*y1+Rectlen/3;
	DrawRec(x1, y1, Rectlen / 2);
}

void DrawPath()
{
	mm.findpath();
	std::vector<std::pair<LL, LL> >::iterator p = mm.path.begin();
	LL x1, y1;
	glColor3d(PATHCOLOR);
	while (p != mm.path.end())
	{
		if ((*p) == endpos)	break;
		x1=(*p).first-SX,x1=Rectlen*x1+Rectlen/5;
		y1=(*p).second-SY,y1=Rectlen*y1+Rectlen/5;
		DrawRec(x1, y1, Rectlen / 5);
		p++;
	}
}

void DrawTrace()
{
	std::vector<std::pair<LL, LL> >::iterator p = mm.trace.begin();
	LL x1, y1;
	glColor3d(TRACECOLOR);
	while (p != mm.trace.end())
	{
		x1=(*p).first-SX,x1=Rectlen*x1+Rectlen/5;
		y1=(*p).second-SY,y1=Rectlen*y1+Rectlen/5;
		DrawRec(x1, y1, Rectlen / 5);
		p++;
	}
}

void DrawExit()
{
	LL x1,y1;
	x1=endpos.first-SX,x1=Rectlen*x1+Rectlen/5;
	y1=endpos.second-SY,y1=Rectlen*y1+Rectlen/5;
	glColor3d(EXITCOLOR);
	DrawRec(x1,y1,Rectlen/5);
}
#endif // !DRAW_H