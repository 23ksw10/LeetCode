#include <iostream>
#include <vector>




using namespace std;




class Solution {
public:
	vector<vector<int>> matrixReshape(vector<vector<int>>& nums, int r, int c) {
		int originalR = nums.size();
		int originalC = nums[0].size();
		if (r*c != originalR * originalC)
			return nums;

		vector<vector<int>>ans(r, vector<int>(c, 0));
		int a = 0, b = 0;
		for (int i = 0; i < r; i++)
		{

			for (int j = 0; j < c; j++)
			{

				ans[i][j] = nums[a][b];
				b++;
				if (b == originalC)
				{
					a++;
					b = 0;
				}


			}


		}
		return ans;
	}
};
