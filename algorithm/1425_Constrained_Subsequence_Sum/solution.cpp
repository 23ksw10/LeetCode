#include <iostream>
#include <vector>
#include <algorithm>
#include <deque>



using namespace std;



class Solution {
public:
	int constrainedSubsetSum(vector<int>& nums, int k) {
		int ans = nums[0];
		int n = nums.size();
		deque<int>dq;
		dq.push_back(nums[0]);
		vector<int>dp(n, 0);
		dp[0] = nums[0];
		for (int i = 1; i < n; i++) {
			if (i > k&&dq[0] == dp[i - k - 1]) {
				dq.pop_front();
			}
			dp[i] = nums[i];
			dp[i] = max(dp[i], dq.front() + nums[i]);
			while (!dq.empty() && dq.back() < dp[i]) {
				dq.pop_back();
			}
			dq.push_back(dp[i]);
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};