        #include<iostream>  
        #include<string.h>  
        #define N 205  
        using namespace std;  
        int s[N];  
        int  dp[N][N];  
        int slove(int n)  
        {     
            int i;  
            for(i=1;i<=n;++i)  
                dp[i][i]=0;  
             for(int k=2;k<=n;++k)  
             {  
                 for(int j=1;j<=n-k+1;++j)  
                 {  
                     i=j+k-1;  
                     dp[j][i]=999999999;  
                       
                     for(int r=j;r<i;++r)  
                         dp[j][i]=min(dp[j][i],(dp[j][r]+dp[r+1][i]+s[j-1]*s[r]*s[i]));  
                 }  
             }  
             return dp[1][n];  
        }  
        int main()  
        {     
            int n;  
            while(cin>>n)  
            {  
                for(int i=0;i<=n;++i) cin>>s[i];  
                cout<<slove(n)<<endl;  
            }return 0;  
        }  


