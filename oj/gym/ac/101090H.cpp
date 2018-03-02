#include <bits/stdc++.h>
using namespace std;
int main()
{
	bool one[100001];
	int k,i,j,l;
	char c;
	cin>>k;
	i=1;
	while(scanf("%c",&c)!=EOF)
	{
		if(c=='\n')	continue;
		if(c-'0'==1)
			one[i]=true;
		else one[i]=false;
		i++;
	}
	for(j=1;j<i;j++)
	{
		if(!one[j])	continue;
		for(l=0;l<i;l=l+k)
		{
			if(l+j+1>=i)	break;
			if(one[l+j+1])
			{
				cout<<j<<" "<<l+j+1<<endl;
				return 0;
			}
		}
	}
	cout<<"0 0"<<endl;
	return 0;
}