#include <iostream>
#include <vector>
#include <algorithm>




using namespace std;


class Solution {
public:
	int lengthOfLongestSubstring(string s) {
		if (!s.size())return 0;
		vector<int>dp(128, 0);
		int l = 0;
		int r = 0;
		int ans = 0;
		int tmp = 0;
		for (; r < s.size();) {
			if (!dp[s[r] - '\0']) {
				dp[s[r] - '\0'] += 1;
				tmp++;
				r++;
			}
			else {

				ans = max(ans, tmp);
				dp[s[r] - '\0'] += 1;
				tmp++;
				while (dp[s[r] - '\0'] != 1) {
					dp[s[l] - '\0'] -= 1;
					l++;
					tmp--;
				}

				r++;
			}
		}
		ans = max(ans, tmp);
		return ans;

	}
};