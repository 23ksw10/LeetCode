#include <iostream>
#include <vector>



using namespace std;


class Solution {
public:
	int numWays(vector<string>& words, string target) {
		long long mod = 10e8 + 7;
		int m = words.size();
		int n = target.size();
		int k = words[0].size();
		vector<vector<long long>>dp(n + 1, vector<long long>(k + 1, 0));
		vector<vector<long long>>freq(k, vector<long long>(26, 0));
		for (int i = 0; i <= k; i++) {
			dp[0][i] = 1;
		}
		for (auto &w : words) {
			for (int i = 0; i < k; i++) {
				int idx = w[i] - 'a';
				freq[i][idx]++;
			}
		}
		for (int i = 1; i <= n; i++) {
			int idx = target[i - 1] - 'a';
			for (int j = i; j <= k; j++) {
				dp[i][j] = (dp[i - 1][j - 1] * freq[j - 1][idx]) % mod;
				dp[i][j] = (dp[i][j] + dp[i][j - 1]) % mod;
			}
		}
		
		return dp[n][k];
	}
};