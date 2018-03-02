#include"include.h"
int judge()
{
	int temp[4][4];
	char key[4]={'w','a','s','d'};
	for(int k=0;k<4;k++)
	{
		for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
			temp[i][j]=map[i][j];
		action(key[k],temp);
		for(int i=0;i<4;i++)
		for(int j=0;j<4;j++)
		{
			if(map[i][j]!=temp[i][j]) return !FAIL;
		}
	}
	return FAIL;
}
