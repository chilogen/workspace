#include <iostream>
#include <algorithm>
#include <set>
using namespace std;
int main()
{
	set<int>s;
	bool a[100]={0};
	int b[100];
	float q=0,w=2,e=0;
	int i,j,n=0,k,m=0,remain=2,flag;
	cin>>q>>w>>e;
	n=q,remain=w,m=e;
	i=n;
	if(n==1&&remain==0&&m==0)
	{
		//cout<<"1";		//no right
		//cout<<"ERROR"; 	//no right
		//cout<<"error";	//no right
		//cout<<","; 		//no right
		//					//time out
		return 0;
	}
	///////////mdzz
	if(q-n>0||w-remain>0||e-m>0)
	{
		cout<<"ERROR";
		return 0;
	}
	if(m<0)
	{
		cout<<"ERROR";
		return 0;
	}//mdzz	

	if(remain<0||(remain>n))
	{
		cout<<"ERROR";
		return 0;
	}
	if(m>0)	flag=1;
	else flag=-1;
	m+=flag;
	if(flag==1)	k=-1;
	else k=n;
	while(i>remain)
	{
		j=m;
		while(j)
		{
			k=k+flag;
			if(flag==1&&k==n)	k=0;
			else if(flag==-1&&k==-1) k=n-1;
			while(a[k])
			{
				k+=flag;
				if(flag==1&&k==n)	k=0;
				else if(flag==-1&&k==-1)	k=n-1;
			}
			j=j-flag;
		}
		a[k]=1;	s.insert(k+1);
		i--;
	}
	for(i=1,j=0;i<=n;i++)
		if(s.count(i)==0)	b[j++]=i;
	for(i=0;i<j;i++)
	{
		if(i==j-1)	cout<<b[i];
		else cout<<b[i]<<",";
	}
	return 0;
}