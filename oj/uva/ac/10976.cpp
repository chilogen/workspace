#include <bits/stdc++.h>
using namespace std;
int main()
{
	int x,y,k,num,X[1100],Y[1100];
	while(scanf("%d",&k)!=EOF)
	{
		num=0;
		for(y=k+1;y<=2*k;y++)
		{
			x=k*y;
			if(x%(y-k)==0)
			{
				X[num]=x/(y-k);
				Y[num++]=y;
			}
		}
		cout<<num<<endl;
		for(x=0;x<num;x++)	cout<<"1/"<<k<<" = "<<"1/"<<X[x]<<" + "<<"1/"<<Y[x]<<endl;
	}
	return 0;
}