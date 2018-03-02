#include <iostream>
#include <vector>
using namespace std;
class edge
{
public:
	int start,end;
	edge():start(0),end(0){}
};
int main()
{
	int n,i,j;
	freopen("abc","r",stdin);
	cin>>n;
	vector <int> v(n+1,-1);
	vector <int> next(n+1,-1);
	edge k[n];
	for(i=0;i<n;i++)
	{
		cin>>k[i].start>>k[i].end;
		if(v[k[i].start]==-1)	v[k[i].start]=i;
		else
		{
			next[i]=v[k[i].start];
			v[k[i].start]=i;
		}
	}
	for(i=0;i<n;i++)
	{
		int j=v[i];
		if(v[i]==-1)	continue;
		cout<<k[v[i]].start<<"->"<<k[v[i]].end<<"  ";
		while(next[j]!=-1)
		{
			cout<<k[next[j]].start<<"->"<<k[next[j]].end<<"  ";
			j=next[j];
		}
		cout<<endl;
	}
	fclose(stdin);
	return 0;
}