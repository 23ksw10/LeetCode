#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <bitset>


using namespace std;


class Solution {
public:
	int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
		unordered_map<bitset<300>, int> um;
		int ans = 0;
		for (auto i : matrix)
		{
			bitset<300>b1;
			bitset<300>b2;
			for (int j = 0; j < matrix[0].size(); j++)
			{
				if (i[j])
					b1.flip(j);
				else
					b2.flip(j);
			}
			ans = max({ ans,++um[b1],++um[b2] });
		}

		return ans;


	}
};