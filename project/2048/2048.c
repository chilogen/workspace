#include"include.h"
int map[4][4]={0};
int score=0;
int main()
{
	map[3][0]=2;
	show(startmenu);
	char command;
	command=getchar();
	switch(command)
	{
		case '1':play(mode1); break;
		case '2':play(mode2); break;
		case '3':show(howtoplay); break;
	}
}
void play(int mode)
{
	switch(mode)
	{
		case mode1:if(p1()==FAIL)
				show(resultfail);
			   else show(resultwin);
		case mode2:if(p2()==FAIL)
				show(resultfail);
			   else show(resultwin);
	}
}
