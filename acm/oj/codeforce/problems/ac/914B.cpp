#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
int main(){
	LL n,i,j,k,l;
	vector<LL>v;
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j;
		v.push_back(j);
	}
	sort(v.begin(),v.end());
	k=v[n-1];	j=0;
	for(i=n-1;i>=0;i--){
		if(v[i]==k)	j++;
		else{
			if(j%2==1){
				cout<<"Conan"<<endl;
				return 0;
			}
			else{
				k=v[i];
				j=1;
			}
		}
	}
	if(j%2==1)	cout<<"Conan"<<endl;
	else cout<<"Agasa"<<endl;
	return 0;
}