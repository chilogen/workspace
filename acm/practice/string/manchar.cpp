#include <bits/stdc++.h>
using namespace std;
#define Maxn 150000
int p[Maxn];
char c[Maxn];
class longestpalindrime{
private:
	string preprocess(string s){
		string t="$#";
		int len=s.length(),i;
		for(i=0;i<len;i++){
			t+=s[i];
			t+='#';
		}
		return t;
	}
	int* endprocess(int *p,int len,int l){
		int i,j,k;
		int* q=new int[len];
		for(i=2,j=0;i<l;i=i+2,j++){
			k=p[i]/2;
			q[j]=p[i]-k;
		}
		return q;
	}
public:
	int* getp(string s){
		int i,id,mx,l,len=s.length();
		s=preprocess(s);
		l=s.length();
		int* p=new int[l];
		id=mx=0;
		for(i=0;i<l;i++){
			p[i]=mx>i?min(p[2*id-i],mx-i):1;
			while(s[i-p[i]]==s[i+p[i]])
				p[i]++;
			if(mx<i+p[i]){
				mx=i+p[i];
				id=i;
			}
		}

		return endprocess(p,len,l);
	}
};
int main(){
	string s;
	cin>>s;
	longestpalindrime p;
	int *a=p.getp(s),i,len=s.length();
	for(i=0;i<len;i++)cout<<a[i]<<" ";
	cout<<endl;
	return 0;
}