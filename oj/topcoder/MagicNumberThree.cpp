#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
class MagicNumberThree{
private:
	LL mod;
public:
	MagicNumberThree(){
		mod=1000000007;
	}
	int countSubsequences(string s){
		LL i,j,k,len=s.length();
		LL w[]={1,0,0};
		for(i=0;i<len;i++){
			LL* tw=new LL(3);
			memcpy(tw,w,3*sizeof(LL));
			k=s[i]-'0';k%=3;
			for(j=0;j<3;j++){
				tw[j]+=w[(j+3-k)%3];
				tw[j]%=mod;
			}
			memcpy(w,tw,3*sizeof(LL));
		}
		return (int)w[0]-1;
	}
}a;
int main(){
	string s;
	cin>>s;
	cout<<a.countSubsequences(s)<<endl;
	return 0;
}