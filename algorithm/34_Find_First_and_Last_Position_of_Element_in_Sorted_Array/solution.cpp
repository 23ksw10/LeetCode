#include <iostream>
#include <vector>



using namespace std;


class Solution {
public:
	vector<int> searchRange(vector<int>& nums, int target) {

		int a = Range(nums, target);
		int b = Range(nums, target + 1) - 1;

		if (a > b)
			return { -1,-1 };

		return { a,b };





	}
	int Range(vector<int>& nums, int target) {

		int high = nums.size() - 1;
		int low = 0;
		int c = high + 1;
		while (low <= high)
		{
			int m = low + (high - low) / 2;
			if (nums[m] >= target)
			{
				c = m;
				high = m - 1;
			}

			if (nums[m] < target)
			{
				low = m + 1;
			}
		}



		return c;

	}

};