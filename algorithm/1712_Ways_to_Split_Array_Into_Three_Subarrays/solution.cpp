#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;



class Solution {
public:
	int waysToSplit(vector<int>& nums) {
		int mod = 1e9 + 7;
		long long ans = 0;
		int n = nums.size();
		vector<int>sum(n, 0);
		sum[0] = nums[0];
		for (int i = 1; i < n; i++) {
			sum[i] = sum[i - 1] + nums[i];
		}
		int l = 0;
		for (l; l < n; l++) {
			if (sum[l] > sum[n - 1] / 3)break;
			auto mid_start = lower_bound(sum.begin() + l + 1, sum.end(), sum[l] * 2) - sum.begin();
			auto mid_end = upper_bound(sum.begin() + l + 1, sum.end() - 1, sum[l] + (sum[n - 1] - sum[l]) / 2) - sum.begin();
			mid_end--;
			int length = mid_end - mid_start + 1;
			ans += max(0, length);


		}
		return ans % mod;
	}
};