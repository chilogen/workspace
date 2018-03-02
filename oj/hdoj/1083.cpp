	#include <bits/stdc++.h>
    using namespace std;  
    #define MAXN 317  
    int LN,RN;//L,R数目  
    int g[MAXN][MAXN], linker[MAXN];  
    bool used[MAXN];  
    int dfs(int L)//从左边开始找增广路径  
    {  
        int R;  
        for(R = 1; R <= RN; R++)  
        {  
            if(g[L][R]!=0 && !used[R])  
            {  
                //找增广路，反向  
                used[R]=true;  
                if(linker[R] == -1 || dfs(linker[R]))  
                {  
                    linker[R]=L;  
                    return 1;  
                }  
            }  
        }  
        return 0;//这个不要忘了，经常忘记这句  
    }  
    int hungary()  
    {  
        int res = 0 ;  
        int L;  
        memset(linker,-1,sizeof(linker));  
        for( L = 1; L <= LN; L++)  
        {  
            memset(used,0,sizeof(used));  
            if(dfs(L) != 0)  
                res++;  
        }  
        return res;  
    }  
    int main()  
    {  
        int t;  
        int p, n;  
        int k, L, R;  
        scanf("%d",&t);  
        while(t--)  
        {  
            scanf("%d%d",&p,&n);  
            memset(g,0,sizeof(g));  
            for(int i = 1; i <= p; i++)  
            {  
                scanf("%d",&k);  
                for(int j = 1; j <= k; j++)  
                {  
                    scanf("%d",&R);  
                    L = i;  
                    g[L][R] = 1;  
                }  
            }  
            LN = p;  
            RN = n;  
            int res = hungary();//最大匹配数  
            //printf("%d\n",res);  
            if(res == p)  
            {  
                printf("YES\n");  
            }  
            else  
            {  
                printf("NO\n");  
            }  
        }  
        return 0 ;  
    }  