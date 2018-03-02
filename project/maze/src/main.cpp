//#define DEBUG
#include <Maze.h>
using namespace std;
int main(int argc,char **argv)
{
	init();

	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE);
	glutInitWindowPosition(0, 0);
	glutInitWindowSize(WindowsWidth, Windowsheight);
	glutCreateWindow(ProgramName.c_str());

	glutDisplayFunc(&DrawFun);
	glutKeyboardFunc(&KeyBordFun);
	glutReshapeFunc(&ScaleFun);
	glutIdleFunc(IdleFun);

	glutMainLoop();

	return 0;
}
