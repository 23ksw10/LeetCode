#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;



class Solution {
public:
	int minimumMountainRemovals(vector<int>& nums) {
		vector<int>up(nums.size(), 0);
		vector<int>down(nums.size(), 0);
		vector<int>v;
		for (int i = 0; i < nums.size(); i++) {
			auto it = lower_bound(v.begin(), v.end(), nums[i]);
			up[i] = distance(v.begin(), it);
			if (it != v.end()) {
				*it = nums[i];
			}
			else {
				v.push_back(nums[i]);
			}
		}
		v.clear();
		for (int i = nums.size() - 1; i >= 0; i--) {
			auto it = lower_bound(v.begin(), v.end(), nums[i]);
			down[i] = distance(v.begin(), it);
			if (it != v.end()) {
				*it = nums[i];
			}
			else {
				v.push_back(nums[i]);
			}
		}

		int ans = 0;
		for (int i = 0; i < up.size(); i++) {
			if (!up[i] || !down[i])continue;
			ans = max(ans, up[i] + down[i] + 1);
		}
		return nums.size() - ans;
	}
};