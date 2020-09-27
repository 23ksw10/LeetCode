#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



using namespace std;

  


class Solution {
public:
	int minDistance(string word1, string word2) {
		int n = word1.size();
		int m = word2.size();
		int ans = 0;
		vector<vector<int>>dp(n + 1, vector<int>(m + 1, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (word1[i] == word2[j]) {
					dp[i + 1][j + 1] = dp[i][j] + 1;
				}
				else {
					dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
				}
			}
		}

		return n - dp[n][m] + m - dp[n][m];

	}
};