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
	int i,j,k,l,m,n,b,g;
	int a[501];
	scanf("%d%d%d%d",&n,&m,&b,&mod);
	for(i=1;i<=n;i++)	scanf("%d",&a[i]);
	for(i=1;i<=b/a[1];i++)
		for(j=1;j<=b/a[2];j++)
			for(k=1;k<=b/a[3];k++)
				for(l=1;l<=b/a[4];l++)
					for(n=1;n<=b/a[5];n++)
					{
						if(i+j+k+l+n==m&&i*a[i]+j*a[j]+k*a[k]+l*a[l]+n*a[n]==b)
							printf("%d %d %d %d %d\n",i,j,k,l,n);
					}
	#ifndef OJ
	fclose(stdin);
	fclose(stdout);
	#endif
}