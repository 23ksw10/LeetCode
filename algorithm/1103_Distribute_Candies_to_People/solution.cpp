#include <iostream>
#include <vector>



using namespace std;




class Solution {
public:
	vector<int> distributeCandies(int candies, int num_people) {
		vector<int>ans(num_people, 0);
		int c = 1;
		int dCandies = 0;
		while (candies > dCandies)
		{
			for (int i = 0; i < num_people; i++)
			{

				if (candies - dCandies >= c)  ans[i] += c;
				else
				{
					ans[i] += candies - dCandies;
					dCandies += c;
					break;
				}
				dCandies += c;
				c++;


			}
		}

		return ans;

	}
};
