#include <bits/stdc++.h>
using namespace std;
int m[100],n;
void print(int k,int a,int b)
{
	int i;
	if(k==2*n)		
	{
		for(i=0;i<2*n;i++)	cout<<m[i]<<" ";
		cout<<endl;
	}
	if(a>0)	m[k]=1,print(k+1,a-1,b);
	if(b>a)	m[k]=0,print(k+1,a,b-1);
}
int main()
{
	cin>>n;
	print(0,n,n);
	return 0;
}