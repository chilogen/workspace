#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
const int MAXN = 86400+10;
const int MAXC = 1000+10;
int n, c;
struct data
{
    int l, r, b;
}datas[MAXN]; 
LL dp1[MAXN], dp2[MAXN], dp1l[MAXN], dp2l[MAXN];

bool cmp(const data& a, const data& b)
{
    return (a.l < b.l) || ((a.l == b.l && a.r < b.r) || (a.l == b.l && a.r == b.r && a.b < b.b));
}

int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d%d", &n, &c);
    for(int i = 1; i <= n; i++)
    {
        int th, tm, ts;
        scanf("%d:%d:%d", &th, &tm, &ts);
        datas[i].l = th * 3600 + tm * 60 + ts;
        scanf("%d:%d:%d", &th, &tm, &ts);
        datas[i].r = th * 3600 + tm * 60 + ts;
        scanf("%d", &datas[i].b);
        datas[i].b -= (datas[i].r - datas[i].l) * c;
    }
    sort(datas+1, datas+n+1, cmp);
    int size = 1;
    for(int i = 2; i <= n; i++)
    {
        if(datas[i].l == datas[size].l && datas[i].r == datas[size].r)
        {
            if(datas[i].b > datas[size].b)
                datas[size] = datas[i];
        }
        else
            datas[++size] = datas[i];
    }
    // 1 : choose
    // 2 : not choose
    LL ans = 0;
    for(int i = 1; i <= n; i++)
    {
        if(datas[i].b > 0)
        {
            dp1[i] = datas[i].b;
            int pos = lower_bound(dp1l+1, dp1l+i, datas[i].l) - dp1l;
            if(datas[i].l == dp1l[pos] && pos != i)
                pos = pos;
            else
                pos --;
            if(dp1[i] + dp1[pos] <= dp1[i] + dp2[pos])
            {
                dp1[i] += dp2[pos];
                dp1l[i] = datas[i].r;
            }
            else
            {
                dp1[i] += dp1[pos];
                dp1l[i] = datas[i].r;
            }
        }
        if(dp1[i-1] > dp2[i-1])
        {
            dp2[i] = dp1[i-1];
            dp2l[i] = dp1l[i-1];
        }
        else
        {
            dp2[i] = dp2[i-1];
            dp2l[i] = dp2l[i-1];
        }
        ans = max(ans, dp2[i]);
        ans = max(ans, dp1[i]);
    }
    cout << ans << endl;
    return 0;
}