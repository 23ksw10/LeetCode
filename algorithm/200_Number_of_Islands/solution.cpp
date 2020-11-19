#include <iostream>
#include <vector>



using namespace std;




class Solution {
public:

	int ud[4] = { -1,0,1,0 };
	int lr[4] = { 0,1,0,-1 };
	int numIslands(vector<vector<char>>& grid) {
		int m = grid.size();
		int n = grid[0].size();
		int ans = 0;
		vector<vector<bool>>check(m, vector<bool>(n, false));
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (!check[i][j] && grid[i][j] == '1') {
					ans++;
					dfs(grid, check, i, j);
				}
			}
		}
		return ans;

	}
	void dfs(vector<vector<char>>& grid, vector<vector<bool>>& check, int x, int y) {
		int m = grid.size();
		int n = grid[0].size();
		check[x][y] = true;
		for (int i = 0; i < 4; i++) {
			if (x + ud[i] >= 0 && x + ud[i] < m&&y + lr[i] >= 0 && y + lr[i] < n&&grid[x + ud[i]][y + lr[i]] == '1') {
				if (check[x + ud[i]][y + lr[i]] == false)dfs(grid, check, x + ud[i], y + lr[i]);

			}
		}
	}
};