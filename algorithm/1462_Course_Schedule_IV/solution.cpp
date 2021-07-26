#include <iostream>
#include <vector>
#include <queue>



using namespace std;


 

class Solution {
public:
	vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
		int n = numCourses;
		vector<int>degree(n, 0);
		bool dp[100][100];
		memset(dp, 0, sizeof(dp));
		vector<vector<int>>g(n);
		for (auto &p : prerequisites) {
			g[p[0]].push_back(p[1]);
			degree[p[1]]++;
		}
		queue<int>q;
		for (int i = 0; i < n; i++) {
			if (!degree[i]) {
				q.push(i);
			}
		}
		while (!q.empty()) {
			int s = q.size();
			for (int i = 0; i < s; i++) {
				auto a = q.front();
				q.pop();
				for (auto &j : g[a]) {
					for (int k = 0; k < n; k++) {
						dp[j][k] |= dp[a][k];
					}
					dp[j][a] = 1;
					if (--degree[j] == 0) {
						q.push(j);
					}
				}
			}
		}
		vector<bool>ans;
		for (auto &q : queries) {
			ans.push_back(dp[q[1]][q[0]]);
		}
		return ans;

	}
};