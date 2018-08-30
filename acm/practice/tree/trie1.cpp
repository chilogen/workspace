#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const LL maxn=6e5+10,bits=3;
struct node{
	node *ch[2];
	LL cnt;
	node(){
		ch[0]=ch[1]=NULL;
		cnt=1;
	}
}root;
LL n,m,cnt;
node *R[maxn];
string tostr(LL x){
	string ans="";
	while(x){
		if(x&1)ans+='1';
		else ans+='0';
		x>>=1;
	}
	while(ans.length()<bits)ans+='0';
	reverse(ans.begin(),ans.end());
	return  ans;
}
LL tonum(string s){
	LL i,ans=0;
	for(i=0;i<bits;i++){
		ans<<=1;
		if(s[i]=='1')ans+=1;
	}
	return ans;
}
void add(LL x,LL y){
	string s=tostr(y);
	node *p1=R[x-1],*p2=new node();
	R[x]=p2;p2->cnt=p1->cnt+1;
	LL i,j,flag=0;
	for(i=0;i<bits;i++){
		j=s[i]-'0';
		p2->ch[j]=new node();
		if(p1==NULL)flag=1;
		if(!flag){
			p2->ch[!j]=p1->ch[!j];
			p1=p1->ch[j];
		}
		p2=p2->ch[j];
		if(p1==NULL)p2->cnt=1;
		else p2->cnt=p1->cnt+1;
	}
}
LL query(LL x,LL y,LL z){
	node *p1=R[x],*p2=R[y];
	string s=tostr(z),ans="";
	LL i,j,flag=0,cl,cr;
	for(i=0;i<bits;i++){
		j=s[i]-'0';
		if(p1==NULL)flag=1;
		if(p2->ch[!j]!=NULL){
			if(!flag){
				cr=p2->ch[!j]->cnt;
				if(p1->ch[!j]==NULL)cl=0;
				else cl=p1->ch[!j]->cnt;
				if(cr-cl>0){
					p1=p1->ch[!j];
					p2=p2->ch[!j];
					ans+='1';
				}
				else{
					p1=p1->ch[j];
					p2=p2->ch[j];
					ans+='0';
				}
			}
			else{
				ans+='1';
				p2=p2->ch[!j];
			}
		}
		else{
			ans+='0';
			p2=p2->ch[j];
			if(!flag)p1=p1->ch[j];
		}
	}
	return tonum(ans);
}
int main(){
	LL i,j,l,r,x;
	char c;
	cin>>n>>m;
	R[0]=&root;root.cnt=0;
	for(i=1;i<=n;i++){
		cin>>j;
		add(i,j);
	}
	cnt=n+1;
	for(i=0;i<m;i++){
		cin>>c>>l;
		if(c=='A')add(cnt++,l);
		else{
			cin>>r>>x;
			cout<<query(l-1,r,x)<<endl;
		}
	}
	return 0;
}