#include <bits/stdc++.h>
#define reset(a,b)	memset(a,b,sizeof(a))
using namespace std;
int pro[110][5];
int main()
{
	int t,q,m,i,j,k,p,l;
	char qu,an,ans[110];
	cin>>t;
	while(t--)
	{
		cin>>q>>m;
		reset(pro,-1);
		for(i=0;i<m;i++)
		{
			for(j=1;j<=q;j++)
			{
				cin>>qu;
				while(qu>'D'||qu<'A')	cin>>qu;
				cin>>an;
				while(an!='T'&&an!='F')	cin>>an;
				k=qu-'A';
				if(an=='T')	pro[j][k]=1;
				else if(an=='F')	pro[j][k]=0;
			}
		}
		k=0;	bool bre;
		for(i=1;i<=q;i++)
		{
			bre=false;
			for(j=0;j<4;j++)
			{
				if(pro[i][j]==1)
				{
					ans[k]='A'+j;
					k++;
					bre=true;
					break;
				}
			}
			if(bre)	continue;
			for(j=0,p=0,l=0;j<4;j++)
			{
				if(pro[i][j]==0)	p++;
				else	l=j;
			}
			if(p==3)
			{
				ans[k]='A'+l;
				k++;
			}
			else
			{
				ans[k]='?';
				k++;
			}
		}
		for(i=0;i<q-1;i++)
			printf("%c ",ans[i]);
		printf("%c\n",ans[i]);
	}
	return 0;
}