#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;


class Solution {
public:

	int orangesRotting(vector<vector<int>>& grid) {
		int col = grid[0].size();
		int row = grid.size();
		int minute = 0;
		int fresh = 0;
		int rotten = 0;
		queue<pair<int, int>>q;
		vector<pair<int, int>> d = { {-1,0},{1,0},{0,-1} ,{0,1} };

		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				if (grid[i][j] == 2)
				{
					q.push({ i,j });
					rotten++;
				}
				if (grid[i][j] == 1)
					fresh++;

			}
		if (fresh == 0) return 0;

		while (!q.empty())
		{
			minute++;
			int n = q.size();
			for (int i = 0; i < n; i++)
			{
				auto a = q.front();
				q.pop();
				for (auto k : d)
				{
					auto i = a.first + k.first;
					auto j = a.second + k.second;
					if (i >= 0 && i < row&&j >= 0 && j < col &&grid[i][j] == 1)
					{
						grid[i][j] = 2;
						q.push({ i,j });

						fresh--;
					}
				}
			}
		}
		if (!fresh) return minute - 1;

		return -1;

	}

};