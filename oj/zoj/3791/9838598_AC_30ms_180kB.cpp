#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include<string.h>

int main()
{
    char str1[101], str2[101];
    long long int n, k, m, i, dp[101][101], j, l, dif = 0, w;
    long long int C[101][101];
    long long int mod = 1e9 + 9;
    C[0][0] = 1;
    for(i = 0; i <= 100; i++){
        C[i][0] = 1;
        C[i][i] = 1;
    }
    for(i = 1; i <= 100; i++){
        for(j = 1; j < i; j++){
            C[i][j] = (C[i - 1][j - 1] + C[i - 1][j]) % mod;
        }
    }
    while (scanf("%lld %lld %lld", &n, &k, &m) != EOF){
        dif = 0;
        memset(dp, 0, sizeof(dp));
        scanf("%s", str1);
        scanf("%s", str2);
        for(i = 0; i < n; i++)
            if (str2[i] != str1[i])
                dif++;
        dp[0][dif] = 1;
        for (i = 0; i < k; i++) {
            for (j = 0; j <= n; j++) {
                for (l = 0; l <= m; l++) {
                    if((j + 2 * l - m) < 0) continue;
                    if((j + 2 * l - m) > n) break;
                    dp[i + 1][j + 2 * l - m] = (dp[i + 1][j + 2 * l - m] % mod + C[j][m - l] * C[n - j][l] % mod * dp[i][j] % mod) % mod;
                 }
            }
        }
        printf("%lld\n", dp[k][0]);
    }
    return 0;
}