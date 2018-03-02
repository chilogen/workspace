#include"include.h"
void action(char command,int m[4][4])
{
	int p[4],q[4];
	switch(command)
	{
		case 'w':
			{
				memset(q,0,sizeof(q));
				for(int j=0;j<4;j++)
				{
					for(int i=0;i<4;i++)
					{
						p[i]=m[i][j];
					}
					q[j]=add(p);
					for(int i=0;i<4;i++)
					{
						m[i][j]=p[i];
					}
				}
				append(q,3,4,m);
				break;
			}
		case 'a':
			{
				memset(q,0,sizeof(q));
				for(int i=0;i<4;i++)
				{
					for(int j=0;j<4;j++)
					{
						p[j]=m[i][j];
					}
					q[i]=add(p);
					for(int j=0;j<4;j++)
					{
						m[i][j]=p[j];
					}
				}
				append(q,4,3,m);
				break;
			}
		case 's':
			{
				memset(q,0,sizeof(q));
				for(int j=0;j<4;j++)
				{
					for(int i=3;i>-1;i--)
					{
						p[3-i]=m[i][j];
					}
					q[j]=add(p);
					for(int i=3;i>-1;i--)
					{
						m[i][j]=p[3-i];
					}
				}
				append(q,0,4,m);
				break;
			}
		case 'd':
			{
				memset(q,0,sizeof(q));
				for(int i=0;i<4;i++)
				{
					for(int j=3;j>-1;j--)
					{
						p[3-j]=m[i][j];
					}
					q[i]=add(p);
					for(int j=3;j>-1;j--)
					{
						m[i][j]=p[3-j];
					}
				}
				append(q,4,0,m);
				break;
			}
	}	
}
