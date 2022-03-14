#include <iostream>
#include <vector>
#include <queue>


using namespace std;

using tiii = tuple<int, int, int>;

class Solution {
public:
	int minCost(vector<vector<int>>& grid) {
		int n = grid.size();
		int m = grid[0].size();
		int lr[4] = { 1,-1,0,0 };
		int ud[4] = { 0,0,1,-1 };
		vector<vector<int>>cost(n, vector<int>(m, INT_MAX));
		priority_queue<tiii, vector<tiii>, greater<tiii>>pq;
		pq.push({ 0,0,0 });
		cost[0][0] = 0;
		while (!pq.empty()) {
			auto [x, r, c] = pq.top();
			pq.pop();
			for (int i = 0; i < 4; i++) {
				int nextR = r + ud[i];
				int nextC = c + lr[i];
				if (nextR >= 0 && nextR < n && nextC >= 0 && nextC < m) {
					int newX = x;
					if (grid[r][c] != i + 1) {
						newX++;
					}
					if (cost[nextR][nextC] > newX) {
						cost[nextR][nextC] = newX;
						pq.push({ newX,nextR,nextC });
					}
				}
			}
		}
		return cost[n - 1][m - 1];
	}
};
