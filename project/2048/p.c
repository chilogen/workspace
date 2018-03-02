#include"include.h"
int p1()
{
	char command;
	while(1)
	{
		//system("stty -echo");
		command=getchar();
		//system("stty echo");
		action(command,map);
		disp();
		for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			if(map[i][j]==2048) return WIN;
		}
		if(judge()==FAIL) return FAIL;
	}
}

int p2()
{
	char command;
	while(1)
	{
		system("stty -echo");
		command=getchar();
		system("stty echo");
		action(command,map);
		disp();
		if(judge()==FAIL) return FAIL;
	}
}
