#include <bits/stdc++.h>
using namespace std;

class MinimizeAbsoluteDifferenceDiv2{
public:
	double getans(double a,double b,double c){
		return abs(a/b-c);
	}
	vector <int> findTriple(int x1, int x2, int x3){
		int x[3]={x1,x2,x3};
		int y[3]={0,1,2};
		double tans,ans=getans((double)x[y[0]],(double)x[y[1]],(double)x[y[2]]);
		int i,j,k;
		for(i=0;i<3;i++){
			for(j=0;j<3;j++){
				if(j==i)continue;
				for(k=0;k<3;k++){
					if(k==j||k==i)continue;
					tans=getans((double)x[i],(double)x[j],(double)x[k]);
					if(ans>tans){
						ans=tans;
						y[0]=i;
						y[1]=j;
						y[2]=k;
					}
				}
			}
		}
		vector<int>v;
		for(i=0;i<3;i++)v.push_back((int)y[i]);
		return v;
	}
	void solve(){
		int i,j;
		vector<int>v;
		for(i=0;i<3;i++){
			cin>>j;
			v.push_back(j);
		}
		v=findTriple(v[0],v[1],v[2]);
		for(i=0;i<3;i++)cout<<v[i]<<endl;
	}
}a;

int main(){
	a.solve();
	return 0;
}