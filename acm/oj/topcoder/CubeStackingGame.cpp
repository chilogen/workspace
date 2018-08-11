#include <bits/stdc++.h>
using namespace std;
class CubeStackingGame{
public:
	int MaximumValue(int n, vector <int> c1, vector <int> c2, vector <int> c3, vector <int> c4){
		v[0]=c1;v[1]=c2;v[2]=c3;v[3]=c4;nn=n;
		dfs(0);
		return maxans;
	}
	CubeStackingGame(){
		maxans=0;
		memset(color,0,sizeof(color));
	}
private:
	int maxans;
	bool color[4][10];
	vector<int>v[4];
	int nn;
	void dfs(int height){
		maxans=max(maxans,height);
		if(height==nn)return;
		int i,j,k;
		int c[4];
		for(i=0;i<=4;i++){
			for(k=0,j=i;k<4;k++,j++){
				if(j==4)j=0;
				c[k]=v[j][height];
			}
			for(k=0;k<4;k++){
				if(color[k][c[k]]!=0)break;
			}
			if(k==4){
				for(j=0;j<4;j++)color[j][c[j]]=1;
				dfs(height+1);
				for(j=0;j<4;j++)color[j][c[j]]=0;
			}
		}
		for(i=0;i<=4;i++){
			for(k=0,j=i;k<4;k++,j++){
				if(j==4)j=0;
				c[k]=v[j][height];
			}
			j=c[0];c[0]=c[2];c[2]=j;
			for(k=0;k<4;k++){
				if(color[k][c[k]]!=0)break;
			}
			if(k==4){
				for(j=0;j<4;j++)color[j][c[j]]=1;
				dfs(height+1);
				for(j=0;j<4;j++)color[j][c[j]]=0;
			}
		}
	}
}a;
int main(){
	int n,i,j,k;
	vector<int>v[4];
	cin>>n;
	for(i=0;i<4;i++){
		for(j=0;j<n;j++){
			cin>>k;
			v[i].push_back(k);
		}
	}
	k=a.MaximumValue(n,v[0],v[1],v[2],v[3]);
	cout<<k<<endl;
	return 0;
}