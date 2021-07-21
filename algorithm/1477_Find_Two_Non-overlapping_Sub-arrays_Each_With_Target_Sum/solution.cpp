#include <iostream>
#include <vector>
#include <algorithm>




using namespace std;


 


class Solution {
public:
	int minSumOfLengths(vector<int>& arr, int target) {
		int ans = INT_MAX;
		vector<int>dp(arr.size(), INT_MAX);
		int l = 0;
		int tmp = 0;
		int min_curr = INT_MAX;
		for (int r = 0; r < arr.size(); r++) {
			tmp += arr[r];
			while (tmp > target) {
				tmp -= arr[l++];

			}
			if (tmp == target) {
				if (l != 0 && dp[l - 1] != INT_MAX)ans = min(ans, dp[l - 1] + r - l + 1);
				min_curr = min(min_curr, r - l + 1);
			}
			dp[r] = min_curr;
		}
		return ans == INT_MAX ? -1 : ans;
	}
};