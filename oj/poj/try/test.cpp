#include <bits/stdc++.h>
using namespace std;
struct t{
	int x,y,v,m;
	t(){x=v=y=m=-1;};
}a[100000],b[100000];
int main(){
	int i;
	for(i=0;i<=100000;i++){
		memcpy(a,b,sizeof(b));
	}
	return 0;
}