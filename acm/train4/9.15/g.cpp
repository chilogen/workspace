#include <bits/stdc++.h>
using namespace std;



int T;
typedef unsigned long long ULL;
typedef long long LL;
ULL ans;
const int MAXN = 1e5+10;
char nums[MAXN];
const ULL mod = 1e9+7;
string num;
int s[MAXN];
ULL pres[MAXN][10];

void Minus(){
	LL i,j,k=1,l=num.length();
	reverse(num.begin(),num.end());
	for(i=0;i<l;i++){
		if(num[i]=='0')num[i]='9';
		else{
			num[i]-=1;
			break;
		}
	}
}


int main()
{
	ULL i,j,k;
    for(i = 0; i < 10; i++)
        pres[0][i] = 1 << i;
    for(i = 1; i < MAXN; i++)
    {
        for(j = 0; j < 10; j++)
        {
            ULL tmp = pres[i-1][j];
            pres[i][j] = 1;
            for(k = 1; k <= 10; k++)
                pres[i][j] = (pres[i][j] * tmp) % mod;
        }
    }
    ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
    cin >> T;
    while(T--)
    {
    	num="";
        cin >> num;
       	Minus();
        ans = 1;
        k=num.length();
        for(i = 0; i < k; i++)
        {
            ans = (ans * pres[i][num[i]-'0']) % mod;
        }
        cout <<  ans << '\n';
    }
    return 0;
}