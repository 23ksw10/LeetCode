#include <iostream>
#include <string>

using namespace std;



class Solution {
public:
	int numJewelsInStones(string J, string S) {
		int ans = 0;
		int rans = 0;

		for (int i = 0; i < J.size(); i++)
		{
			char k = J[i];

			for (int j = 0; j < S.size(); j++)
			{
				if (S[j] == k)
				{
					ans++;
				}
			}


		}
		return ans;

	}
};

