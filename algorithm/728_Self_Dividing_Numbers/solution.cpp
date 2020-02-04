#include <iostream>
#include<vector>



using namespace std;

class Solution {
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector<int> ans;
		for (int i = left; i <= right; i++)
		{
			int n = i;
			bool check = 1;
			if (n % 10 != 0)
			{
				while (n > 0)

				{
					int a = n % 10;
					if (a == 0 || i % (a) != 0)
					{
						check = 0;
						break;
					}


					n /= 10;

				}
				if (check)

					ans.push_back(i);

			}
		}
		return ans;

	}
};

