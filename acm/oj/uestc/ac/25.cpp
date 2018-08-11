

#include <bits/stdc++.h>
using namespace std;
char board[2][100];
int main(){
	int n,i,j,l,k,len;
	string s,t;
	string no="on ";
	while(1){
		cin>>n;
		memset(board,0,sizeof(board));
		if(n==0)break;
		for(i=0;i<n;i++){
			getchar();
			getline(cin,s);
			len=s.length();
			for(j=len-6,t="";j>=len-8;j--){
				t+=s[j];
			}
			board[i%2][i/2]=t==no?'X':'O';
		}
		j=n/2+n%2;
		for(i=0;i<j;i++)cout<<i+1<<" ";
		cout<<"Score\n";
		for(i=0;i<2;i++){
			l=0;
			for(k=0;k<j;k++){
				if(board[i][k]!='X'&&board[i][k]!='O')cout<<"- ";
				else cout<<board[i][k]<<" ";
				if(board[i][k]=='O')l++;
			}
			cout<<l<<endl;
		}
	}
	return 0;
}

