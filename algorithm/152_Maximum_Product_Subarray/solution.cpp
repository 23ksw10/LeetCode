#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;




class Solution {
public:
	int maxProduct(vector<int>& nums) {
		if (!nums.size())return 0;
		int ans = nums[0];
		int ma = nums[0];
		int mi = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			int tmp = ma;
			ma = max({ nums[i],ma*nums[i],mi*nums[i] });
			mi = min({ nums[i],tmp*nums[i],mi*nums[i] });
			ans = max({ ans,ma,mi });
		}
		return ans;
	}
};