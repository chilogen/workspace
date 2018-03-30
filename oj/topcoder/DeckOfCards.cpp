#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
class DeckOfCards{
public:
	string IsValid(int n, vector <int> value, string suit){
		LL i,j,k,l,len=suit.length(),a,b;
		for(i=0;i<len;i++){
			j=suit[i]-'a';
			v[j].push_back(value[i]);
		}
		for(i=0;i<26;i++){
			sort(v[i].begin(),v[i].end());
			k=v[i].size();
			if(k==0)continue;
			for(j=1,m[i][v[i][0]]=1;j<k;j++){
				if(v[i][j]==v[i][j-1])break;
				m[i][v[i][j]]=1;
			}
			if(j!=k)break;
		}
		if(i!=26)return "Not perfect";
		bool perfect=true;
		for(i=0;i<26&&perfect;i++){
			a=v[i].size();
			for(j=0;j<a&&perfect;j++){
				for(k=i+1;k<26&&perfect;k++){
					b=v[k].size();
					for(l=0;l<b&&perfect;l++){
						if(m[i][v[k][l]]==0)perfect=false;
						if(m[k][v[i][j]]==0)perfect=false;
					}
				}
			}
		}
		if(perfect)return "Perfect";
		else return "Not perfect";
	}
private:
	vector<LL>v[26];
	map<LL,LL>m[26];
}a;
int main(){
	vector<int>v;
	string s;
	LL i,j,k;
	cin>>j;
	for(i=0;i<j;i++){
		cin>>k;
		v.push_back(k);
	}
	cin>>s;
	s=a.IsValid(j,v,s);
	cout<<s<<endl;
	return 0;
}