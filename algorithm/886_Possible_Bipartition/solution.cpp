#include <iostream>
#include <vector>




using namespace std;


class Solution {
public:
	bool dfs(vector<vector<int>>&g, int i, vector<int>&color, vector<bool>&check, int c) {
		check[i] = true;
		color[i] = c;
		for (auto a : g[i]) {
			if (!check[a]) {
				if (dfs(g, a, color, check, c ^ 1) == false)return false;
			}
			else {
				if (color[i] == color[a])return false;
			}
		}
		return true;
	}
	bool possibleBipartition(int N, vector<vector<int>>& dislikes) {
		vector<vector<int>>g(N + 1);
		vector<bool>check(N + 1, false);
		vector<int>color(N + 1, -1);
		for (auto d : dislikes) {
			g[d[0]].push_back(d[1]);
			g[d[1]].push_back(d[0]);
		}
		for (int i = 1; i <= N; i++) {
			if (!check[i]) {
				if (!dfs(g, i, color, check, 0))return false;
			}
		}
		return true;
	}
};