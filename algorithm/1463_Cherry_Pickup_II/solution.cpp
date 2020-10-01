#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;

class Solution {
public:

	int cherryPickup(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		int r, c1, c2;
		int dp[n][m][m];
		int i, j, k;
		memset(dp, -1, sizeof(dp));


		dp[0][0][m - 1] = grid[0][0] + grid[0][m - 1];

		for (r = 1; r < n; r++) {
			for (c1 = 0; c1 < m; c1++) {
				for (c2 = 0; c2 < m; c2++) {
					for (int i = -1; i <= 1; i++) {
						for (int j = -1; j <= 1; j++) {
							if (c1 + i >= 0 && c1 + i < m&&c2 + j >= 0 && c2 + j < m&&dp[r - 1][c1 + i][c2 + j] != -1) {
								int add;
								if (c1 == c2) add = grid[r][c1];
								else add = grid[r][c1] + grid[r][c2];
								dp[r][c1][c2] = max(dp[r][c1][c2], dp[r - 1][c1 + i][c2 + j] + add);
							}
						}
					}

				}
			}
		}


		int ans = 0;
		for (j = 0; j < m; j++) {
			for (k = 0; k < m; k++) {
				if (ans < dp[n - 1][j][k]) ans = dp[n - 1][j][k];
			}
		}
		return ans;
	}
};