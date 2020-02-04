#include <iostream>
#include <string>
#include<vector>


using namespace std;

class Solution {
public:
	int oddCells(int n, int m, vector<vector<int>>& indices) {
		int ans = 0;
		vector<vector<int>> im(n, vector<int>(m, 0));
		for (int i = 0; i < indices.size(); i++)
		{

			for (int k = 0; k < m; k++)
				im[indices[i][0]][k] += 1;
			for (int j = 0; j < n; j++)
				im[j][indices[i][1]] += 1;

		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (im[i][j] % 2 == 1)
					ans++;

		return ans;

	}
};

