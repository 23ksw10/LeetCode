#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
	vector<bool>b;
	vector<vector<int>>m;
	void dfs(int j) {
		b[j] = true;
		for (int i = 0; i < m[0].size(); i++) {
			if (m[j][i] && !b[i]) dfs(i);
		}
	}
	int findCircleNum(vector<vector<int>>& M) {
		b = vector<bool>(M.size(), false);
		m = M;
		int ans = 0;
		for (int i = 0; i < M.size(); i++) {
			if (b[i])continue;
			b[i] = true;
			for (int j = 0; j < M[i].size(); j++) {
				if (M[i][j] && !b[j]) {
					dfs(j);
				}
			}
			ans++;
		}
		return ans;
	}
};