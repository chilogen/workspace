#include<iostream>
using namespace std;
int main(){
    int t;
    long long n;
    cin>>t;
    while(t--){
        int res=0;
        cin>>n;
        if(n&(n-1))
            res++;
        while(n>1){
            n/=2;
            res++;
        }
        cout<<res<<endl;
    }
}