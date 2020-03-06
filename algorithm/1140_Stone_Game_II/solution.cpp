#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class Solution {
public:
	int stoneGameII(vector<int>& piles) {
		int l = piles.size();
		vector<int>sum(l);
		sum[l - 1] = piles[l - 1];
		for (int i = l - 2; i >= 0; i--)
		{
			sum[i] = piles[i] + sum[i + 1];
		}

		vector<vector<int>> dp(l + 1, vector<int>(l + 1, 0));

		for (int i = l - 1; i >= 0; i--)
			for (int j = l - 1; j >= 0; j--)
				for (int x = 1; x <= 2 * j&&i + x <= l; x++)
				{
					dp[i][j] = max(dp[i][j], sum[i] - dp[i + x][max(j, x)]);
				}
		return dp[0][1];

	}
};