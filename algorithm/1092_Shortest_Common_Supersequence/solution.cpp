#include <iostream>
#include <string>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
    string shortestCommonSupersequence(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                if (str1[i - 1] == str2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                }
                else {
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
                }
            }
        }
        int i = n;
        int j = m;
        string ans = "";
        while (i > 0 || j > 0) {
            if (j > 0 && dp[i][j] == dp[i][j - 1]) {
                ans = str2[j - 1] + ans;
                j--;
            }
            else if (i > 0 && dp[i][j] == dp[i - 1][j]) {
                ans = str1[i - 1] + ans;
                i--;
            }
            else {
                ans = str1[i - 1] + ans;
                i--;
                j--;
            }


        }
        return ans;

    }
};

