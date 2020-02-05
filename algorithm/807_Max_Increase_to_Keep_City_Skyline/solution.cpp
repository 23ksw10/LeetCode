#include <iostream>
#include <vector>

using namespace std;



class Solution {
public:
	int maxIncreaseKeepingSkyline(vector<vector<int>>& grid) {
		vector<int> tb;
		vector<int> lr;
		int min = 0;

		int ans = 0;

		int max = 0;
		for (int i = 0; i < grid.size(); i++)
		{
			for (int j = 0; j < grid[i].size(); j++)
			{

				if (grid[i][j] > max)
					max = grid[i][j];

			}
			lr.push_back(max);
			max = 0;

		}


		for (int j = 0; j < grid[0].size(); j++)
		{

			for (int i = 0; i < grid.size(); i++)
			{
				if (grid[i][j] > max)
					max = grid[i][j];
			}
			tb.push_back(max);
			max = 0;
		}
		vector<vector<int>> gridNew(lr.size(), vector<int>(tb.size(), 0));

		for (int i = 0; i < lr.size(); i++)
		{
			min = lr[i];
			for (int j = 0; j < tb.size(); j++)
			{
				if (tb[j] < min)

					gridNew[i][j] = tb[j];
				else
					gridNew[i][j] = min;
			}

		}

		for (int i = 0; i < lr.size(); i++)
		{

			for (int j = 0; j < tb.size(); j++)
			{
				int n = gridNew[i][j];
				int p = grid[i][j];
				ans += n - p;
			}

		}

		return ans;
	}
};