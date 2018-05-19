/*
  
                                _oo0oo_
                               088888880
                               88" . "88
                               (| -_- |)
                                0\ = /0
                             ___/'---'\___
                           .' \\\\|     |// '.
                          / \\\\|||  :  |||// \\
                         /_ ||||| -:- |||||- \\
                        |   | \\\\\\  -  /// |   |
                        | \_|  ''\---/''  |_/ |
                        \  .-\__  '-'  __/-.  /
                      ___'. .'  /--.--\  '. .'___
                   ."" '<  '.___\_<|>_/___.' >'  "".
                  | | : '-  \'.;'\ _ /';.'/ - ' : | |
                  \  \ '_.   \_ __\ /__ _/   .-' /  /
              ====='-.____'.___ \_____/___.-'____.-'=====
                                '=---='

            ^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^
             AC  AC  AC  AC  AC  AC  AC  AC  AC  AC  AC  AC
     
*/
#define OJ
#include <bits/stdc++.h>
#define pb push_back
#define _1 first
#define _2 second
#define FOR(i,a,b) for(int i=a;i<(b);i++)
#define FORN(i,b) for(int i=0;i<(b);i++)
#define reset(a,b) memset(a,b,sizeof(a))
#define MAX(a,b)  a>b?a:b
#define MIN(a,b)  a>b?b:a
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> pii;
typedef vector<int> vi;
typedef vector<pair<int,int> > vii;

int main()
{
	#ifndef OJ
	freopen("abc.in","r",stdin);
	freopen("abc.out","w",stdout);
	#endif
	int n,a[66],left,right;
	int i,j,k,l;
	scanf("%d",&n);
	for(i=0;i<n-1;i++)
		a[i]=i+2;
	for(i=1;i<n;i++)
	{
		printf("%d %d ",1,a[i-1]);
		left=i%(n-1);	right=(i+n-3)%(n-1);
		for(j=1;j<n/2;j++)
		{
			printf("%d %d ",a[left],a[right]);
			left++;	right=right+n-2;
			left%=(n-1);	right%=(n-1);
		}
		printf("\n");
	}
	#ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
}