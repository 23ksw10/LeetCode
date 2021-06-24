#include <iostream>
#include <vector>


using namespace std;


 

class Solution {
public:
	bool isInterleave(string s1, string s2, string s3) {
		int s_1 = s1.size();
		int s_2 = s2.size();
		int s_3 = s3.size();
		if (s_1 + s_2 != s_3) return false;
		vector<vector<int>>dp(s_1 + 1, vector<int>(s_2 + 1, 0));
		dp[0][0] = 1;
		for (int i = 1; i < s_1 + 1; i++) {
			if (dp[i - 1][0] == 1 && s1[i - 1] == s3[i - 1])dp[i][0] = 1;
		}
		for (int j = 1; j < s_2 + 1; j++) {
			if (dp[0][j - 1] == 1 && s2[j - 1] == s3[j - 1])dp[0][j] = 1;
		}

		for (int i = 1; i < s_1 + 1; i++) {
			for (int j = 1; j < s_2 + 1; j++) {

				if (dp[i - 1][j]) {
					if (s3[i + j - 1] == s1[i - 1])dp[i][j] = 1;
				}
				if (dp[i][j - 1]) {
					if (s3[i + j - 1] == s2[j - 1])dp[i][j] = 1;
				}

			}
		}

		return dp[s_1][s_2];
	}
};