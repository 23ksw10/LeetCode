#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

  
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0)return 0;
		if (nums.size() == 1)return nums[0];
		int p1 = nums[0];
		int p2 = 0;
		for (int i = 1; i < nums.size(); i++) {
			int t = p1;
			if (p2 + nums[i] > p1)p1 = p2 + nums[i];
			p2 = t;
		}
		return max(p1, p2);
	}
};