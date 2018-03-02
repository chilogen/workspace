#include <iostream>
using namespace std;
typedef struct 
{
	int x,y;
}monster;
monster *m;
void print(int n)
{
	int i;
	for(i=0;i<n;i++)
		cout<<m[i].x<<" "<<m[i].y<<endl;
}
int main()
{
	int n,i;
	cin>>n;
	m=new monster[n];
	for (i=0;i<n;i++)
		cin>>m[i].x>>m[i].y;
	delete [] m;
	cin>>m[0].x>>m[1].y;
	print(n);
	return 0;
}