#include<stdio.h>
#include<iostream>
#include<string.h>
#include<string>
#include<ctype.h>
#include<math.h>
#include<set>
#include<map>
#include<vector>
#include<queue>
#include<bitset>
#include<algorithm>
#include<time.h>
using namespace std;
const int N = 3e5 + 10;
typedef long long LL;
LL n;
int v[65555];
int popcount(LL x){
  return v[x&65535]+v[x>>16&65535]+v[x>>32&65535]+v[x>>48];
}
int main()
{
    for(int i=1;i<65536;i++)v[i]=v[i>>1]+(i&1);
    while(~scanf("%lld", &n))
    {
        LL len = 0;
        int one = 0;
        while(n)
        {
            ++len;
            one += n & 1;
            n /= 2;
        }
         
        LL bott = 1ll << (len - 1);
        int bot = sqrt(bott) + 0.99999999;
        LL topp = (1ll << len) - 1;
        int top = sqrt(min(topp, (LL)1e18));
        //printf("%lld %lld\n", bott, topp);
        //printf("%d %d\n", bot, top);
        int ans = 0;
        LL val = (LL)bot * bot, add = bot * 2 + 1;
        int i=bot;
        for(;i+4<=top;i+=4){
            if(popcount(val) == one)++ans;
            val += add, add += 2;
            if(popcount(val) == one)++ans;
            val += add, add += 2;
            if(popcount(val) == one)++ans;
            val += add, add += 2;
            if(popcount(val) == one)++ans;
            val += add, add += 2;
        }
        for(; i <= top; ++i, val += add, add += 2)
        {
            //printf("%d %lld\n", i, val);
            //val = (LL)i * i;
            if(popcount(val) == one)++ans;
        }
        printf("%d\n", ans);
    }
    return 0;
}