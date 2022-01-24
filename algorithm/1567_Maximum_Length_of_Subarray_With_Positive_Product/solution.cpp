#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


 
 
class Solution {
public:
	int getMaxLen(vector<int>& nums) {
		int n = nums.size();
		int ans = 0;
		vector<vector<int>>dp(n, vector<int>(2, 0));
		if (nums[0] > 0) {
			dp[0][0] = 1;
			ans = 1;
		}
		else if (nums[0] < 0) {
			dp[0][1] = 1;
		}
		for (int i = 1; i < n; i++) {
			if (nums[i] > 0) {
				if (dp[i - 1][0])dp[i][0] = dp[i - 1][0] + 1;
				else dp[i][0] = 1;
				if (dp[i - 1][1])dp[i][1] = dp[i - 1][1] + 1;
				else dp[i][1] = 0;
			}
			else if (nums[i] < 0) {
				if (dp[i - 1][1])dp[i][0] = dp[i - 1][1] + 1;
				else dp[i][0] = 0;
				if (dp[i - 1][0])dp[i][1] = dp[i - 1][0] + 1;
				else dp[i][1] = 1;
			}
			ans = max(ans, dp[i][0]);
		}
		return ans;
	}
};