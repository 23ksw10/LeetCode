#include <iostream>
#include <vector>




using namespace std;


 
 
class Solution {
public:
	int matrixScore(vector<vector<int>>& grid) {
		int ans = 0;
		int n = grid.size();
		int m = grid[0].size();
		for (int i = 0; i < n; i++) {
			if (grid[i][0] == 0) {
				for (int j = 0; j < m; j++) {
					grid[i][j] = grid[i][j] ^ 1;
				}
			}
		}


		for (int i = 1; i < m; i++) {
			int count = 0;
			for (int j = 0; j < n; j++) {
				if (grid[j][i] == 0)count++;
			}
			if (count > n - count) {
				for (int j = 0; j < n; j++) {
					grid[j][i] = grid[j][i] ^ 1;
				}
			}
		}

		for (int i = 0; i < n; i++) {
			int k = 1;
			for (int j = m - 1; j >= 0; j--) {
				if (grid[i][j])ans += k;
				k = k << 1;
			}

		}
		return ans;
	}
};