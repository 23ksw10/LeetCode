#include <iostream>
#include <vector>






using namespace std;


 
class Solution {
public:
	int arraySign(vector<int>& nums) {
		int n = nums.size();
		int negative = 0;
		for (int i = 0; i < n; i++) {
			if (!nums[i])return 0;
			if (nums[i] < 0)negative++;
		}
		return negative % 2 ? -1 : 1;
	}
};