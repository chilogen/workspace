#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



const int MOD = 1000000007;

string str1, str2, str3;
long long dp[55][2];

int main() {
    while (cin >> str1 >> str2 >> str3) {
        if (str1 == "0") break;
        
        reverse(str1.begin(), str1.end());
        reverse(str2.begin(), str2.end());
        reverse(str3.begin(), str3.end());        
        int n = str3.size();

        dp[0][0] = 1; dp[0][1] = 0;
        for (int i = 0; i < n; ++i) {
            int no_no = 0, no_up = 0, up_no = 0, up_up = 0;
            
            int start = 0;
            if (i == n-1) start = 1;
            
            for (int a = start; a < 10; ++a) {
                if (str1[i] != '?' && str1[i] != (char)(a + '0')) continue;
                
                for (int b = start; b < 10; ++b) {
                    if (str2[i] != '?' && str2[i] != (char)(b + '0')) continue;
                    
                    for (int c = start; c < 10; ++c) {
                        if (str3[i] != '?' && str3[i] != (char)(c + '0')) continue;
                        
                        if (a + b == c) ++no_no;
                        else if (a + b + 1 == c) ++up_no;
                        else if (a + b == c + 10) ++no_up;
                        else if (a + b + 1 == c + 10) ++up_up;
                    }
                }
            }
                        
            dp[i+1][0] = (dp[i][0] * no_no + dp[i][1] * up_no) % MOD;
            dp[i+1][1] = (dp[i][0] * no_up + dp[i][1] * up_up) % MOD;
        }
        
        cout << dp[n][0] << endl;
    }              
    
    return 0;
}




