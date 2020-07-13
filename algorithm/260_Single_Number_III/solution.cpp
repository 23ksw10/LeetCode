#include <iostream>
#include <vector>



using namespace std;




class Solution {
public:
	vector<int> singleNumber(vector<int> nums) {
		vector<int>ans(2, 0);
		int a = 0;
		for (int i = 0; i < nums.size(); i++) {
			a = a ^ nums[i];
		}
		int dif = a & -a;
		for (int i = 0; i < nums.size(); i++) {
			if (nums[i] & dif) {
				ans[0] = nums[i] ^ ans[0];
			}
			else {
				ans[1] = nums[i] ^ ans[1];
			}
		}
		return ans;
	}
};