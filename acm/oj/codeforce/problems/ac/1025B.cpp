#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
LL n,a,b;
queue<LL>q;

struct Prime{
	int maxn;
	vector<int>list;
	bool *vis;
	Prime(int x):maxn(x),vis(NULL){}
	void init(){
		int i;
		vis=new bool[maxn];
		memset(vis,0,sizeof(bool)*maxn);
		for(i=2;i<maxn;i++){
			if(!vis[i])list.push_back(i);
			vector<int>::iterator p=list.begin();
			while(p!=list.end()&&i*(*p)<maxn){
				vis[i*(*p)]=1;
				if(i%(*p)==0)break;
				p++;
			}
		}
		delete vis;
	}
}p(300000);

bool vis[300010]={0};

void add(LL x){
	LL i=-1;
	while(x>1){
		i++;
		if(i==(LL)p.list.size())break;
		if(x%p.list[i]==0&&!vis[p.list[i]]){
			vis[p.list[i]]=1;
			q.push(p.list[i]);
		}
		while(x%p.list[i]==0)x/=p.list[i];
	}
	if(x!=1)q.push(x);
}

int main(){
	LL i,k;
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>a>>b;
	p.init();
	k=sqrt(max(a,b));
	add(a);add(b);
	for(i=1;i<=k+1;i++){
		if(a%i==0)add(i);
		if(b%i==0)add(i);
	}
	n--;
	while(n--){
		cin>>a>>b;
		k=q.size();
		while(k--){
			i=q.front();q.pop();
			if(a%i==0)q.push(i);
			else if(b%i==0)q.push(i);
		}
	}
	q.push(-1);
	cout<<q.front()<<endl;
	return 0;
}