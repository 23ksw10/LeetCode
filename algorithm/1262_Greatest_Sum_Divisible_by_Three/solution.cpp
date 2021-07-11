#include <iostream>
#include <vector>
#include <algorithm>




using namespace std;


 


class Solution {
public:
	int maxSumDivThree(vector<int>& nums) {
		vector<int>dp(3, 0);
		for (int i = 0; i < nums.size(); i++) {
			vector<int>tmp(3, 0);
			for (int j = 0; j < 3; j++) {
				int k = dp[j] + nums[i];
				if (tmp[k % 3] < k)tmp[k % 3] = k;
			}
			for (int l = 0; l < 3; l++) {
				dp[l] = max(dp[l], tmp[l]);
			}
		}
		return dp[0];
	}
};