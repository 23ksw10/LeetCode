#include <iostream>
#include <vector>



using namespace std;



class Solution {
public:
	int search(vector<int>& nums, int target) {
		int l = 0;
		int r = nums.size() - 1;
		int ans = 100000;
		while (l <= r) {
			int m = l + (r - l) / 2;
			if (nums[m] == target) {
				ans = m;
				return ans;
				break;
			}
			if (nums[m] > target) r = m - 1;
			else l = m + 1;

		}
		return -1;

	}
};