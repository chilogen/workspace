#include <bits/stdc++.h>
using namespace std;
int cnt[10]={0};
void count(int x){
	while(x){
		cnt[x%10]++;
		x/=10;
	}
}
int main(){
	for(int i=1;i<=79;i++)count(i);
	for(int i=0;i<10;i++)cout<<cnt[i]<<" ";
}