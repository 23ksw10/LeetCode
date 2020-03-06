#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


class Solution {
public:

	int maxAreaOfIsland(vector<vector<int>>& grid) {
		int ans = 0;
		int r = grid.size();
		int c = grid[0].size();
		vector<vector<int>> seen(r, vector<int>(c, 0));
		for (int i = 0; i < r; i++)
			for (int j = 0; j < c; j++)
			{
				int land = 0;
				help(grid, seen, i, j, land);
				ans = max(ans, land);
			}

		return ans;


	}
	void help(vector<vector<int>>& grid, vector<vector<int>> &seen, int i, int j, int &land)
	{
		int r = grid.size();
		int c = grid[0].size();
		if (grid[i][j] && !seen[i][j])
		{
			land++;
			seen[i][j] = 1;
			help(grid, seen, min(i + 1, r - 1), max(j, 0), land);
			help(grid, seen, max(i - 1, 0), max(j, 0), land);
			help(grid, seen, min(i, r - 1), min(j + 1, c - 1), land);
			help(grid, seen, min(i, r - 1), max(j - 1, 0), land);
		}
	}
};