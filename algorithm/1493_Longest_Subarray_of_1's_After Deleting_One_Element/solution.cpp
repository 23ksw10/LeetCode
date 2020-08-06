#include <iostream>
#include <vector>
#include<string>
#include <algorithm>


using namespace std;



class Solution {
public:
	int longestSubarray(vector<int>& nums) {
		int l = 0;
		int r = 0;
		int delete_count = 0;
		int ans = 0;
		for (int i = 0; i < nums.size(); i++) {
			if (delete_count) {
				if (nums[i])r++;
				else {
					ans = max(ans, l + r);
					l = r;
					r = 0;

				}
			}
			else {
				if (nums[i])l++;
				else {
					delete_count = 1;

				}
			}
		}
		ans = max(ans, l + r);
		if (!delete_count)ans--;
		return ans;
	}
};