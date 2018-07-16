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
	int ModulePow(int x,int y,int mod){
		int ans=1,tmp=x;
		while(y){
			if(y&1){
				ans*=tmp;
				ans%=mod;
			}
			y=y>>1;
			tmp*=tmp;
			tmp%=mod;
		}
		return ans;
	}
	bool Fermat_Test(int x){
		int i,j;
		srand((unsigned)time(NULL));
		for(i=0;i<10;i++){
			j=rand()%(x-1)+1;
			if(ModulePow(j,x-1,x)!=1)return false;
		}
		return true;
	}
	bool isprime(int x){
		if(x<2)return false;
		return Fermat_Test(x);
		//return Miller_Rabin_Test(x);
		return true;
	}
};
int main(){
	Prime a(100);
	a.init();
	a.show();
	cout<<a.isprime(99)<<endl; 
	return 0;
}