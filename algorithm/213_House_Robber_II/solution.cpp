#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

  
class Solution {
public:
	int rob(vector<int>& nums) {
		if (nums.size() == 0)return 0;
		if (nums.size() == 1)return nums[0];
		if (nums.size() == 2)return max(nums[0], nums[1]);
		int p1 = nums[0];
		int p2 = 0;
		int ans1 = 0;
		int ans2 = 0;
		for (int i = 1; i < nums.size() - 1; i++) {
			int t = p1;
			if (p2 + nums[i] > p1)p1 = p2 + nums[i];
			p2 = t;
		}
		ans1 = max(p1, p2);
		cout << ans1;
		p1 = nums[1];
		p2 = 0;
		for (int i = 2; i < nums.size(); i++) {
			int t = p1;
			if (p2 + nums[i] > p1)p1 = p2 + nums[i];
			p2 = t;
		}
		ans2 = max(p1, p2);
		cout << ans2;
		return max(ans1, ans2);


	}
};