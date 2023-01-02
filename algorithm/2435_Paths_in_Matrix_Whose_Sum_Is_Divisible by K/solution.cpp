#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	int mod = 1e9 + 7;
	int dp(int i, int j, int n, int m, int k, int sum, vector<vector<int>>& grid, vector<vector<vector<int>>>&v) {
		if (i == n - 1 && j == m - 1) {
			sum = (sum + grid[i][j]) % k;
			return sum == 0 ? 1 : 0;
		}
		if (v[i][j][(sum) % k] != -1)return v[i][j][(sum) % k];
		int a = 0;
		int b = 0;
		if (i != n - 1) {
			a = dp(i + 1, j, n, m, k, sum + grid[i][j], grid, v);

		}
		if (j != m - 1) {
			b = dp(i, j + 1, n, m, k, sum + grid[i][j], grid, v);

		}
		v[i][j][sum%k] = (a + b) % mod;
		return v[i][j][sum%k] % mod;
	}
	int numberOfPaths(vector<vector<int>>& grid, int k) {
		int ans = 0;
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<vector<int>>>v(n, vector<vector<int>>(m, vector<int>(k, -1)));
		return dp(0, 0, n, m, k, 0, grid, v);
	}
};

