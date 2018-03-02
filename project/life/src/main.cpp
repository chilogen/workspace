//
// Created by a on 12/25/17.
//

#include <life.h>

int main(int argc, char **argv)
{

    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB|GLUT_DOUBLE);
    glutInitWindowPosition(0,0);
    glutInitWindowSize(WindowHeight,WindowWidth);
    glutCreateWindow("life");

    glutDisplayFunc(DrawFun);
    glutMouseFunc(MouseFun);
    glutKeyboardFunc(KeyboardFun);
    glutIdleFunc(IdleFun);

    glutMainLoop();
    return 0;
}
