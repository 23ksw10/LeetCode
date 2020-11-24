#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;




class Solution {
public:
	int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		if (!n)return 0;
		int dp[n];
		dp[0] = nums[0];
		int ans = nums[0];
		for (int i = 1; i < n; i++) {
			dp[i] = max(nums[i], dp[i - 1] + nums[i]);
			ans = max(ans, dp[i]);
		}
		return ans;
	}
};