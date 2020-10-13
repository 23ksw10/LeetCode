#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

class Solution {
public:
	vector<vector<int>>ans;
	vector<bool>vis;
	void help(vector<int>& nums, int cnt, vector<int>tmp) {
		if (cnt == nums.size()) {
			ans.push_back(tmp);
			return;
		}
		for (int i = 0; i < nums.size(); i++) {
			if (vis[i] || (i&&nums[i] == nums[i - 1] && !vis[i - 1])) { continue; }
			tmp.push_back(nums[i]);
			vis[i] = true;
			help(nums, cnt + 1, tmp);
			vis[i] = false;
			tmp.pop_back();
		}
	}
	vector<vector<int>> permuteUnique(vector<int>& nums) {
		sort(nums.begin(), nums.end());
		vis = vector<bool>(nums.size(), false);
		help(nums, 0, {});
		return ans;
	}
};