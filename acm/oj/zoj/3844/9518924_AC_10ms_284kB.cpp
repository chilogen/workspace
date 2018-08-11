#include <iostream>
#include <algorithm>
using namespace std;
typedef long long LL;
bool cmp(const int &a,const int &b){return a>b;}
int main()
{
	int T,n,i,num;
	int less[10],great[10];
	cin>>T;
	while(T--)
	{
		cin>>n;
		num=0;
		for(i=0;i<n;i++)
		{
			cin>>less[i];
			great[i]=less[i];
		}
		sort(less,less+n);	sort(great,great+n,cmp);
		while(less[0]!=great[0])
		{
			num++;
			if(num>3000000)	break;
			i=great[0]-less[0];
			less[0]=great[0]=less[n-1]=great[n-1]=i;
			sort(less,less+n);	sort(great,great+n,cmp);
		}
		if(less[0]==great[0])	cout<<less[0]<<endl;
		else cout<<"Nooooooo!"<<endl;

	}
	return 0;
}