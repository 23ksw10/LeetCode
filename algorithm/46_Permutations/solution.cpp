#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	vector<vector<int>> permute(vector<int>& nums) {
		vector<vector<int>> ans;
		help(nums, ans, 0);

		return ans;

	}
	void help(vector<int> nums, vector<vector<int>> &ans, int begin)
	{
		if (begin == nums.size() - 1)
			ans.push_back(nums);
		for (int i = begin; i < nums.size(); i++)
		{
			swap(nums[begin], nums[i]);
			help(nums, ans, begin + 1);
		}
	}
};