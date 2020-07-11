#include <iostream>
#include <vector>



using namespace std;




class Solution {
public:

	vector<vector<int>>ans;
	int max;
	void dfs(vector<int>& nums, vector<int> &p, int count) {
		if (count == nums.size()) {
			return;

		}
		ans.push_back(p);
		for (int i = count; i < nums.size(); i++) {
			p.push_back(nums[i]);
			dfs(nums, p, count + 1);
			p.pop_back();
		}

	}
	vector<vector<int>> subsets(vector<int>& nums) {

		vector<int>p;
		dfs(nums, p, 0);

		ans.push_back({});
		return ans;

	}
};