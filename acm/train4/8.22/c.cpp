#include <bits/stdc++.h>
using namespace std;
typedef unsigned long long ULL;
const int MAXN = 20;
int n;
int chis[MAXN], eggs[MAXN];
int star[MAXN];
ULL ans;
bool used[MAXN];

void dfs(int pos)
{
    if(!star[pos])
        return;
    for(int i = star[pos]; i <= n; i++)
    {
        if(used[i])
            continue;
        if(pos < n)
        {
            used[i] = true;
            dfs(pos+1);
            used[i] = false;
        }
        else
        {
            ans ++;
        }
    }
}


int main()
{
    // freopen("in.txt", "r", stdin);
    scanf("%d", &n);
    for(int i = 1; i <= n; i++)
        scanf("%d", &chis[i]);
    for(int i = 1; i <= n; i++)
        scanf("%d", &eggs[i]);
    sort(chis+1, chis+n+1);
    sort(eggs+1, eggs+n+1);
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            if(eggs[j] >= chis[i])
            {
                star[i] = j;
                break;
            }
        }
    }
    dfs(1);
    cout << ans << '\n';
    return 0;
}