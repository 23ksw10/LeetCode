#include <iostream>
#include <vector>




using namespace std;

  


class Solution {
public:
	int smallestDivisor(vector<int>& nums, int threshold) {
		int n = nums.size();
		int r = nums[n - 1];
		int l = 1;
		int ans = 0;
		while (l <= r) {
			int mid = l + (r - l) / 2;
			int check = 0;
			for (auto n : nums) {
				if (n%mid)check += n / mid + 1;
				else check += n / mid;
			}
			if (check <= threshold) {
				r = mid - 1;
				ans = mid;
			}
			else {
				l = mid + 1;
			}
		}
		return ans;
	}
};