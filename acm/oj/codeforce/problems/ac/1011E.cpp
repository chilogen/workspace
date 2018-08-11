#include <bits/stdc++.h>
using namespace std;
int main(){
    int n,m,i,l;
    int a[100010];
    cin>>n>>m;
    for(i=0;i<n;i++)cin>>a[i];
    l=m;
    for(i=0;i<n;i++)l=__gcd(l,a[i]);
    cout<<m/l<<endl;
    for(i=0;i<m;i+=l)cout<<i<<" ";
    return 0;
}