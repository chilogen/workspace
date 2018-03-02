#include"include.h"
void show(int page)
{
	if(page==startmenu)
	{
		//system("clear");
		printf("***********************************************************\n");
		printf("*                                                         *\n");
		printf("*                            2048                         *\n");
		printf("*                                                         *\n");
		printf("*  1----play mode1                                        *\n");
		printf("*  2----play mode2                                        *\n");
		printf("*  3----howtoplay                                         *\n");
		printf("*  4----exit                                              *\n");
		printf("*                                                         *\n");
		printf("*                                                         *\n");
		printf("***********************************************************\n");
	}
	else if(page==howtoplay)
	{
		system("clear");
		printf("***********************************************************\n");
		printf("*                                                         *\n");
		printf("*  use w a s d                                            *\n");
		printf("*  mode1 is infinite mode                                 *\n");
		printf("*  mode2 is 2048 win mode                                 *\n");
		printf("*                                                         *\n");
		printf("*                                                         *\n");
		printf("*                                                         *\n");
		printf("*                                                         *\n");
		printf("*                                                         *\n");
		printf("***********************************************************\n");
	}
	else if(page==resultwin)
	{
		//system("clear");
		for(int i=0;i<4;i++)
		{
			printf("------------------\n");
			printf("| %d | %d | %d | %d |\n",map[i][0],map[i][1],map[i][2],map[i][3]);
		}
			printf("------------------\n");
		printf("you score is:%d",score);
	}
	else if(page==resultfail)
        {
                system("clear");
                for(int i=0;i<4;i++)
                {
			printf("------------------\n");
                        printf("| %d | %d | %d | %d |\n",map[i][0],map[i][1],map[i][2],map[i][3]);
                }
			printf("------------------\n");
                printf("you score is:%d",score);
        }   
}
void disp()
{		
	//system("clear");
        for(int i=0;i<4;i++)
        {
		printf("------------------\n");
               	printf("| %d | %d | %d | %d |\n",map[i][0],map[i][1],map[i][2],map[i][3]);
        }
		printf("------------------\n");
        printf("you score is:%d",score);
}
