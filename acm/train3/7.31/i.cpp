#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL inf=1e15;
map<string,LL>ma;
struct planet{
	double x,y,z;
}pla[80];
inline double Dist(planet a,planet b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y)+(a.z-b.z)*(a.z-b.z));
}
LL t,p,w,q;
double d[80][80],ansd[80][80];
struct node{
	LL x;
	double w;
};
struct cmp{
	bool operator()(node a,node b){
		return a.w>b.w;
	}
};
void dijkstra(LL x){
	priority_queue<node,vector<node>,cmp>q;
	LL i;
	for(i=0;i<p;i++)ansd[x][i]=inf;
	ansd[x][x]=0;q.push((node){x,0});
	node tn;
	while(!q.empty()){
		tn=q.top();q.pop();
		if(tn.w!=ansd[x][tn.x])continue;
		for(i=0;i<p;i++){
			if(ansd[x][i]>ansd[x][tn.x]+d[tn.x][i]){
				ansd[x][i]=ansd[x][tn.x]+d[tn.x][i];
				q.push((node){i,ansd[x][i]});
			}
		}
	}
}
void floyd(){
	LL i,j,k;
	for(k=0;k<p;k++)for(i=0;i<p;i++)for(j=0;j<p;j++)
		d[i][j]=min(d[i][k]+d[k][j],d[i][j]);
}
int main(){
	LL Kase=1,i,j;
	string ts1,ts2;
	cin>>t;
	while(t--){
		cout<<"Case "<<Kase++<<":\n";
		ma.clear();
		cin>>p;
		for(i=0;i<p;i++){
			for(j=0;j<p;j++)d[i][j]=inf;
			cin>>ts1;
			ma[ts1]=i;
			cin>>pla[i].x>>pla[i].y>>pla[i].z;
		}
		for(i=0;i<p;i++){
			for(j=0;j<p;j++){
				d[i][j]=Dist(pla[i],pla[j]);
			}
		}
		cin>>w;
		for(i=0;i<w;i++){
			cin>>ts1>>ts2;
			d[ma[ts1]][ma[ts2]]=0;
		}
		for(i=0;i<p;i++)
			dijkstra(i);
		//floyd();
		cin>>q;
		for(i=0;i<q;i++){
			cin>>ts1>>ts2;
			j=ansd[ma[ts1]][ma[ts2]]+0.5;
			cout<<"The distance from "<<ts1<<" to "<<ts2<<" is "<<(LL)round(ansd[ma[ts1]][ma[ts2]])<<" parsecs.\n";
			//cout<<"The distance from "<<ts1<<" to "<<ts2<<" is "<<round(d[ma[ts1]][ma[ts2]])<<" parsecs.\n";

		}
	}
	return 0;
}