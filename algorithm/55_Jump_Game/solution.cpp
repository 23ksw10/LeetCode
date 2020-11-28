#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;






class Solution {
public:
	bool canJump(vector<int>& nums) {
		int max_step = 0;
		for (int i = 0; i < nums.size(); i++) {
			max_step = max(nums[i] + i, max_step);
			if (max_step == i)break;
		}

		return max_step >= nums.size() - 1;
	}
};