#include <iostream>
#include <algorithm>


using namespace std;


class Solution {
public:
	int dp[59];
	int dfs(int i, int n) {
		if (dp[i] != -1)return dp[i];
		for (int j = 1; j < i; j++) {
			dp[i] = max(max(dfs(j, n), j)*max(dfs(i - j, n), i - j), dp[i]);
		}
		return dp[i];
	}
	int integerBreak(int n) {
		memset(dp, -1, sizeof(dp));
		dp[1] = 1;
		dp[2] = 1;
		dp[10] = 36;
		return dfs(n, n);
	}
};