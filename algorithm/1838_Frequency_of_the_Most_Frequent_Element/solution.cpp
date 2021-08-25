#include <iostream>
#include <vector>
#include <algorithm>





using namespace std;


 
 
class Solution {
public:
	int maxFrequency(vector<int>& nums, int k) {
		sort(nums.begin(), nums.end());
		int l = 0;
		int r = 0;
		int ans = 0;
		long long sum = 0;
		while (r < nums.size()) {
			sum += nums[r];
			while ((long long)nums[r] * (r - l + 1) > sum + k) {
				sum -= nums[l];
				l++;
			}
			ans = max(ans, r - l + 1);
			r++;
		}
		return ans;
	}
};