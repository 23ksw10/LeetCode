#include <iostream>
#include <vector>
#include <algorithm>
#include<queue>


using namespace std;



class Solution {
public:
	int closedIsland(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		int ans = 0;

		queue<pair<int, int>>q;
		for (int i = 0; i < grid.size(); i++) {
			for (int j = 0; j < grid[0].size(); j++) {
				if (!grid[i][j]) {
					q.push({ i,j });
					grid[i][j] = true;
					bool check = true;;
					while (!q.empty()) {
						int size = q.size();
						for (int i = 0; i < size; i++) {
							auto it = q.front();
							q.pop();
							auto l = make_pair(it.first, max(it.second - 1, 0));
							auto r = make_pair(it.first, min(it.second + 1, m - 1));
							auto u = make_pair(max(it.first - 1, 0), it.second);
							auto d = make_pair(min(it.first + 1, n - 1), it.second);

							if (!grid[l.first][l.second]) {
								if (l.second == 0)check = false;
								grid[l.first][l.second] = 1;
								q.push(l);

							}
							if (!grid[r.first][r.second]) {
								if (r.second == m - 1)check = false;
								grid[r.first][r.second] = 1;
								q.push(r);

							}
							if (!grid[u.first][u.second]) {
								if (u.first == 0)check = false;
								grid[u.first][u.second] = 1;
								q.push(u);

							}
							if (!grid[d.first][d.second]) {
								if (d.first == n - 1)check = false;
								grid[d.first][d.second] = 1;
								q.push(d);

							}
						}
					}
					if (i == 0 || i == n - 1 || j == 0 || j == m - 1)check = false;
					if (check)ans++;

				}

			}
		}
		return ans;

	}
};