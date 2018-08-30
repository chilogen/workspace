#include <bits/stdc++.h>
using namespace std;
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
	void show(){
		vector<int>::iterator p=list.begin();
		while(p!=list.end()){
			cout<<*p<<" ";
			p++;
		}
		cout<<endl;
	}
}p(1000000001);
int main(){
	p.init();
	cout<<p.list.size()<<endl;
}