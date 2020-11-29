#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;






class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if (!amount)return 0;
		int ans = 0;
		int m = 1000000;
		vector<int>dp(amount + 1, m);
		dp[0] = 0;
		for (auto a : coins) {
			for (int i = a; i <= amount; i++) {
				if (dp[i - a] != m)dp[i] = min(dp[i], dp[i - a] + 1);
			}
		}
		if (dp[amount] != m)return dp[amount];
		return -1;
	}
};