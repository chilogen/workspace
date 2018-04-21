#include <bits/stdc++.h>
using namespace std;

struct edge{
	int u,v;
};

class Deadfish{
public:
	edge e[1000000];
	int cnt,vis[4000010]={0},dst[4000010];
	vector<int>v[400010];
	int shortestCode(int N){
		int i,j,k,l,m;
		for(i=0;i<=2*N;i++){
			j=i-1;k=i*i;l=i+1;m=resort(i);
			if(j>0)connect(i,j);
			if(i<500&&k!=i&&k<=2*N)connect(i,k);
			if(l<=N)connect(i,l);
			if(m<=2*N&&m!=i)connect(i,m);
		}
		queue<int>bfs;
		vis[0]=1;bfs.push(0);
		while(1){
			i=bfs.front();bfs.pop();
			vector<int>::iterator p=v[i].begin();
			while(p!=v[i].end()){
				edge &te=e[*p];
				if(!vis[te.v]){
					vis[te.v]=1;
					dst[te.v]=dst[i]+1;
					bfs.push(te.v);
					if(te.v==N) return dst[N];
				}
				p++;
			}
		}
	}
	int resort(int x){
		if(x==0)return 0;
		int flag=x/abs(x);
		x=abs(x);
		int a[10],i,j=0,k=0;
		while(x){
			a[k++]=x%10;
			x/=10;
		}
		sort(a,a+k,greater<int>());
		for(i=0;i<k;i++){
			j*=10;
			j+=a[i];
		}
		return j*flag;
	}
	void connect(int x,int y){
		e[cnt].u=x;e[cnt].v=y;
		v[x].push_back(cnt++);
	}
	void solve(){
		cout<<shortestCode(200000)<<endl;
	}
}a;
int main(){
	a.solve();
	return 0;
}
/*
Problem Statement
Deadfish+ is a programming language with only 4 commands. All commands modify a single register. 
The register is initially set to zero, and during the execution of a program it can store an 
arbitrarily large integer value. The commands are:

    "i" - increment the value,
    "d" - decrement the value,
    "s" - square the value, and
    "p" - sort the digits of the number into non-increasing order (i.e., biggest to smallest). 

For example, "p" changes 4070 to 7400, and it changes -4070 to -7400 (the minus sign is preserved).

You are given an N. Return the minimal number of commands necessary to make the register hold the number N.
Definition
Class:
Deadfish
Method:
shortestCode
Parameters:
int
Returns:
int
Method signature:
int shortestCode(int N)
(be sure your method is public)
Limits
Time limit (s):
2.000
Memory limit (MB):
256
Constraints
- N will be between 1 and 200,000, inclusive.
Examples
0)
3
Returns: 3
The fastest way to get to 3 is "iii" - three increments.
1)
5
Returns: 4

One fastest way to get a 5 is "iisi": two increments to get a 2, 
square to get a 4 and one more increment.

Another optimal way is "ddsi": two decrements change the register 
to -2, squaring that gives 4, and the final increment changes it to 5.
2)
15
Returns: 5
The fastest way to get 15 is "iissd". The value in the register 
will change as follows: 0, 1, 2, 4, 16, 15.
3)
61
Returns: 5
The fastest way to get 61 is "iissp". The value in the register
 will change as follows: 0, 1, 2, 4, 16, 61.
4)
200000
Returns: 207
This problem statement is the exclusive and proprietary property 
of TopCoder, Inc. Any unauthorized use or reproduction of this 
information without the prior written consent of TopCoder, Inc. 
is strictly prohibited. (c)2003, TopCoder, Inc. All rights reserved. 
*/