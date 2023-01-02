#include <iostream>
#include <vector>
#include <queue>

using namespace std;


class Solution {
public:
	int ud[8] = { -1,-1,0,1,1,1,0,-1 };
	int lr[8] = { 0,1,1,1,0,-1,-1,-1 };
	int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;
		int n = grid.size();
		int m = grid[0].size();
		vector<vector<int>>visit(n, vector<int>(m, INT_MAX));
		if (grid[0][0] == 1)return -1;
		pq.push({ 1,0,0 });
		visit[0][0] = 1;
		while (pq.size()) {
			auto[length, r, c] = pq.top();
			if (r == n - 1 && c == n - 1)return length;
			pq.pop();
			for (int i = 0; i < 8; i++) {
				int nr = r + ud[i];
				int nc = c + lr[i];
				if (nr >= 0 && nr < n&&nc >= 0 && nc < n) {
					if (grid[nr][nc] == 0 && visit[nr][nc] > length + 1) {
						pq.push({ length + 1,nr,nc });
						visit[nr][nc] = length + 1;
					}
				}
			}
		}

		return -1;
	}
};

