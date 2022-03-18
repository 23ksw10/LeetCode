#include <iostream>
#include <vector>




using namespace std;

class Solution {
public:
    long long getDescentPeriods(vector<int>& prices) {
        long long ans = 0;
        int n = prices.size();
        vector<long long>dp(n, 0);
        for (int i = 0; i < n; i++) {
            if (i > 0) {
                if (dp[i - 1] > 1) {
                    dp[i] = dp[i - 1] - 1;
                    continue;
                }
            }
            int count = 1;
            int idx = i;
            while (idx + 1 < n && prices[idx] == prices[idx + 1] + 1) {
                count++;
                idx++;
            }
            dp[i] = count;
        }
        for (auto& d : dp) {
            ans += d;
        }
        return ans;
    }
};