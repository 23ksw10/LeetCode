#include <iostream>
#include <vector>
#include <algorithm>




using namespace std;


class Solution {
public:
	int findMaxLength(vector<int>& nums) {
		int ans = 0;
		int n = nums.size();
		vector<int> indexOf(2 * n + 1, -1);
		int sum = 0;

		for (int i = 0; i < n; i++)
		{
			sum += (!nums[i]) ? -1 : 1;

			if (sum == 0) ans = max(ans, i + 1);

			if (indexOf[sum + n] != -1) ans = max(ans, i - indexOf[sum + n]);
			else indexOf[sum + n] = i;
		}

		return ans;
	}
};