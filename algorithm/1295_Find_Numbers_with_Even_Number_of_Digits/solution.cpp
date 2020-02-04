#include <iostream>
#include <string>
#include<vector>
using namespace std;



class Solution {
public:
	int findNumbers(vector<int>& nums) {
		int ans = 0;
		for (int i = 0; i < nums.size(); i++)
		{
			if (9 < nums[i] && nums[i] < 100)
				ans++;
			else if (999 < nums[i] && nums[i] < 10000)
				ans++;
			else if (99999 < nums[i] && nums[i] < 1000000)
				ans++;
		}
		return ans;
	}
};
