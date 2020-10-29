#include <iostream>
#include <string>
#include <algorithm>




using namespace std;


class Solution {
public:
	int minDistance(string word1, string word2) {
		int s1 = word1.size();
		int s2 = word2.size();
		int dp[s1 + 1][s2 + 1];
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < s1; i++) {
			dp[i + 1][0] = i + 1;
		}
		for (int i = 0; i < s2; i++) {
			dp[0][i + 1] = i + 1;
		}
		for (int i = 0; i < s1; i++) {
			for (int j = 0; j < s2; j++) {
				if (word1[i] == word2[j])dp[i + 1][j + 1] = dp[i][j];
				else dp[i + 1][j + 1] = min({ dp[i][j + 1],dp[i + 1][j],dp[i][j] }) + 1;
			}
		}

		return dp[s1][s2];
	}
};