#include <bits/stdc++.h>
using namespace std;
string s;
string ans1="Panic!\n",ans2="No panic\n";
int main(){
    int i,len,j,k;
    cin>>s;
    len=s.length();
    for(i=0;i<len;i++)if(s[i]!='A')break;
    j=i;
    for(;i<len;i++)if(s[i]!='!')break;
    k=i-j;
    if(j!=0&&k!=0&&i==len)cout<<ans1;
    else cout<<ans2;
    return 0;
}