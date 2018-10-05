#include <bits/stdc++.h>
using namespace std;
int n, m;
typedef long long LL;
const LL mod = 1e9+7;
LL ans = 0;
int sizep;
int primes[10000];
int tt = 1;

LL inv(LL x, LL MOD) 
{
    if(x == 1)
    {
        return 1;
    }
    return inv(MOD % x, MOD) * (MOD - MOD / x) % MOD;
}

LL calc(LL k)
{
    LL t = n / k;
    // LL tmp = ((t*(t+1)%mod)%mod*k/2%mod + (t*(t+1)%mod*(2*t+1))%mod*k*k%mod/6)%mod;
    LL tmp = ((t*(t+1)%mod*k%mod)*inv(2, mod)%mod + (t*(t+1)%mod*(2*t+1)%mod*k%mod*k%mod)*inv(6, mod)%mod) % mod;
    return tmp;
}

bool used[10000];
void search(int pos, int maxn, int mul)
{
    for(int i = 1; i <= sizep; i++)
    {
        if(used[i])
            continue;
        if(pos < maxn)
        {
            used[i] = true;
            search(pos+1, maxn, mul*primes[i]);
            used[i] = false;
        }
        else
        {
            ans = (ans + tt * calc(mul*primes[i]) + mod) % mod;
        }
    }
}

int main()
{
    // freopen("in.txt", "r", stdin);
    while(~scanf("%d%d", &n, &m))
    {
        ans = calc(1);
        sizep = 0;
        LL tm = m;
        for(int i = 2; i*i <= tm; i++)
        {
            if(tm % i == 0)
            {
                primes[++sizep] = i;
                while(tm % i == 0)
                {
                    tm /= i;
                }
            }
        }
        if(tm != 1)
            primes[++sizep] = tm;
        sort(primes, primes+sizep);
        for(int i = 1; i <= sizep; i++)
        {
            if(i % 2 == 1)
                tt = -1;
            else
                tt = 1;
            memset(used, 0, sizeof(used));
            search(1, i, 1);
        }
        printf("%llu\n", (ans+mod)%mod);
    }
    return 0;
}