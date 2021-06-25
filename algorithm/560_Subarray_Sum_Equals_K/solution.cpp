#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;


 

class Solution {
public:
	unordered_map<int, int>dp;
	int subarraySum(vector<int>& nums, int k) {
		int ans = 0;
		int n = nums.size();
		dp[0] = 1;
		int tmp = 0;
		int s = 0;
		for (int i = 0; i < n; i++) {
			s += nums[i];
			ans += dp[s - k];
			tmp += nums[i];
			dp[tmp]++;
		}
		return ans;
	}
};