#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

class Solution {
public:
	vector<vector<int>> threeSum(vector<int>& nums) {
		vector<vector<int>>ans;
		if (nums.size() < 3)return ans;
		sort(nums.begin(), nums.end());
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] > 0)return ans;
			if (i > 0 && nums[i] == nums[i - 1])continue;
			int l = i + 1;
			int r = nums.size() - 1;
			while (l < r) {
				if (nums[l] + nums[r] + nums[i] == 0) {
					ans.push_back({ nums[i],nums[l],nums[r] });
					int lv = nums[l];
					while (l < r&&lv == nums[l]) {
						l++;
					}
					int rv = nums[r];
					while (l < r&&rv == nums[l]) {
						r--;
					}

				}
				if (nums[l] + nums[r] + nums[i] > 0)r--;
				if (nums[l] + nums[r] + nums[i] < 0)l++;

			}
		}
		return ans;

	}
};