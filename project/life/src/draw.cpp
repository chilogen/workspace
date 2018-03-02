//
// Created by a on 12/25/17.
//

#include <life.h>

void DrawRect(int x, int y, int len)
{
    glBegin(GL_POLYGON);

    glVertex2d(x, y);
    glVertex2d(x + len, y);
    glVertex2d(x + len, y + len);
    glVertex2d(x, y + len);

    glEnd();
}

void DrawLine(int x1,int y1,int x2,int y2)
{
    glBegin(GL_LINES);
    glVertex2d(x1,y1);
    glVertex2d(x2,y2);
    glEnd();
}

void DrawFun()
{
    int i,j;
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, WindowWidth, 0, WindowHeight);
    glClearColor(BACKGROUNDCOLOR);
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3d(POINTCOLOR);
    for(i=1;i<=pixelx;i++)
        for(j=1;j<=pixely;j++)
            if(m[i][j]) DrawRect(i*blocklen,j*blocklen,blocklen);

    glColor3d(LINECOLOR);
    for(i=1;i<=pixelx;i++)
        DrawLine(i*blocklen,0,i*blocklen,WindowWidth);
    for(j=1;j<=pixely;j++)
        DrawLine(0,j*blocklen,WindowHeight,j*blocklen);


    glutSwapBuffers();
    if(!p)  evolution();
}
void MouseFun(int button,int state,int x,int y)
{
    int sx,sy,ex,ey,i,j;
    if(button==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
    {
        y=WindowWidth-y;
        x=x/blocklen,y=y/blocklen;
        sx=(x-pixelsize/2<1?1:x-pixelsize/2);
        sy=(y-pixelsize/2<1?1:y-pixelsize/2);
        ex=(x==pixelx?pixelx:x+pixelsize/2);
        ey=(y==pixely?pixely:y+pixelsize/2);
        for(i=sx;i<=ex;i++)
            for(j=sy;j<=ey;j++)
                m[i][j]=1;
    }
}
void KeyboardFun(unsigned char c,int x,int y)
{
    p=(c=='p'?!p:p);
    if(c=='q')  exit(1);
}

void IdleFun()
{
    glutPostRedisplay();
}
