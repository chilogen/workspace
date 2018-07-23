//something wrong with find,be careful with it

#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
string s,ts="happiness";
vector<LL>ans;
void fun1(){
  LL i,j,l=s.length();
  for(i=0;i<l;i++){
    for(j=0;j<9;j++)
      if(s[i+j]!=ts[j])break;
    if(j==9)ans.push_back(i+1);
  }
}
bool fun2(){
  LL i,j,l=s.length();
  for(i=0;i<l;i++){
    for(j=0;j<9;j++)if(s[i+j]!=ts[j])break;
    if(j==9)return true;
  }
  return false;
}
int main(){
  cin>>s;
  if(s.length()<9){
    cout<<"YES\n1 2\n";
    return 0;
  }
  fun1();
  if(ans.size()>2)cout<<"NO\n";
  else{
    cout<<"YES\n";
    if(ans.size()==0){
      swap(s[0],s[1]);
      if(!fun2())cout<<"1 2\n";
      else cout<<"1 3\n";
    }
    if(ans.size()==1){
      cout<<ans[0]<<" "<<ans[0]+1<<endl;
    }
    if(ans.size()==2){
      cout<<ans[0]<<" "<<ans[1]+1<<endl;
    }
  }
  return 0;
}