#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
struct query{
	ULL l,r,ans,ind;
	query(ULL a,ULL b,ULL c){
		l=a;
		r=b;
		ind=c;
		ans=0;
	}
};
bool cmp1(query a,query b){return a.r<b.r;}
bool cmp2(query a,query b){return a.ind<b.ind;}
vector<query>q;
string str;
ULL len,n;
ULL m[100010],s[100010],a=163;
void solve(){
	ULL l,r,ta,k;
	l=r=1;ta=s[0];k=0;
	vector<query>::iterator p=q.begin();
	while(p!=q.end()){
		query &tq=*p;
		while(tq.r>r){
			ta*=a;
			r++;k++;
			ta+=s[r-1];
		}
		while(tq.l>l){
			ta-=(s[l-1]*m[k]);
			l++;k--;
		}
		while(tq.l<l){
			l--;k++;
			ta+=(s[l-1]*m[k]);
		}
		tq.ans=ta;
		p++;
	}
}
int main(){
	ios::sync_with_stdio(false);
	ULL i,j,k;
	cin>>str;
	len=str.length();
	for(i=0;i<len;i++)s[i]=str[i]-'a';
	cin>>n;
	for(i=0;i<n;i++){
		cin>>j>>k;
		q.push_back(query(j,k,i));
	}
	m[0]=1;
	for(i=1;i<100010;i++)m[i]=m[i-1]*a;
	sort(q.begin(),q.end(),cmp1);
	solve();
	sort(q.begin(),q.end(),cmp2);
	for(i=0;i<n;i++)cout<<q[i].ans<<endl;
	return 0;
}