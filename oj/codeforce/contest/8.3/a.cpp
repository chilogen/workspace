#include <bits/stdc++.h>
using namespace std;
int main()
{
	int temp=0,ma=0,n,i,j,k;
	char a;
	cin>>n;	getchar();
	for(i=0;i<n;i++)
	{
		scanf("%c",&a);
		if(a>='A'&&a<='Z')	temp++;
		else if(a==' ')
		{
			ma=max(ma,temp);
			temp=0;
		}
	}
	ma=max(ma,temp);
	cout<<ma<<endl;
	return 0;
}