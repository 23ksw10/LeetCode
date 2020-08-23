#include <iostream>
#include <vector>






using namespace std;




class Solution {
public:
	int search(vector<int>& nums, int target) {
		int r = nums.size() - 1;
		int l = 0;
		while (l <= r) {
			if (nums[l++] == target)return l - 1;
			if (nums[r--] == target) return r + 1;

		}
		return -1;
	}
};