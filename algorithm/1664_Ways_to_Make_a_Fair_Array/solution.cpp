#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;



class Solution {
public:
	int waysToMakeFair(vector<int>& nums) {
		int ans = 0;
		int n = nums.size();
		vector<pair<int, int>>dp(n);
		dp[0] = { 0,nums[0] };
		for (int i = 1; i < n; i++) {
			if (i % 2) {
				dp[i].first = dp[i - 1].first + nums[i];
				dp[i].second = dp[i - 1].second;
			}
			else {
				dp[i].second = dp[i - 1].second + nums[i];
				dp[i].first = dp[i - 1].first;
			}

		}
		for (int i = 0; i < n; i++) {
			int even = 0;
			int odd = 0;
			if (i % 2) {
				even = dp[i].second + dp[n - 1].first - dp[i].first;
				odd = dp[i].first + dp[n - 1].second - dp[i].second - nums[i];
			}
			else {
				even = dp[i].second + dp[n - 1].first - dp[i].first - nums[i];
				odd = dp[i].first + dp[n - 1].second - dp[i].second;
			}
			if (even == odd)ans++;

		}
		return ans;
	}
};