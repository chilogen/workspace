#include <iostream>
using namespace std;
int n;
char a[60],b[60][60];
int main()
{
	int i,j,k;
	for(i=0;i<26;i++)	a[i]='A'+i;
	for(;i<52;i++)		a[i]='a'+i-26;
	while(scanf("%d",&n)!=EOF)
	{
		cout<<2<<" "<<n<<" "<<n<<endl;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				b[i][j]=a[i];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cout<<b[i][j];
			cout<<endl;
		}
		cout<<endl;
		for(i=0;i<n;i++)
			for(j=0;j<n;j++)
				b[i][j]=a[j];
		for(i=0;i<n;i++)
		{
			for(j=0;j<n;j++)
				cout<<b[i][j];
			cout<<endl;
		}
		cout<<endl;
	}
	return 0;
}