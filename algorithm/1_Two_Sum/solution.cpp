#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
	vector<int> twoSum(vector<int>& nums, int target) {


		vector<int>b;
		for (int i = 0; i < nums.size() - 1; i++)
		{
			int t1 = nums[i];

			for (int j = i + 1; j < nums.size(); j++)
			{
				int t2 = nums[j];
				if (t1 + t2 == target)
				{
					b.push_back(i);
					b.push_back(j);


				}


			}
		}
		return b;

	}
};