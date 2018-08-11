#include <bits/stdc++.h>
using namespace std;
struct stud{
	int id,sum;
}s[1100];
int n;
bool cmp(stud x,stud y){
	if(x.sum==y.sum)return x.id<y.id;
	else return x.sum>y.sum;
}
int main(){
	int i,j,k,l;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j>>k>>l>>s[i].sum;
		s[i].sum+=(j+k+l);
		s[i].id=i;
	}
	sort(s,s+n,cmp);
	for(i=0;i<n;i++)if(s[i].id==0){
		cout<<i+1<<endl;
		break;
	}
	return 0;
}