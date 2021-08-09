#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>




using namespace std;


 

 
class Solution {
public:
	int largestPathValue(string colors, vector<vector<int>>& edges) {
		int n = colors.size();
		vector<int>degree(n, 0);
		vector<vector<int>>g(n);
		for (auto &e : edges) {
			degree[e[1]]++;
			g[e[0]].push_back(e[1]);
		}
		queue<int>q;
		vector<vector<int>>dp(n, vector<int>(26, 0));
		for (int i = 0; i < n; i++) {
			if (!degree[i]) {
				dp[i][colors[i] - 'a']++;
				q.push(i);
			}
		}
		if (q.size() == 0)return -1;
		int ans = 0;
		int seen = 0;
		while (!q.empty()) {
			auto a = q.front();
			q.pop();
			seen++;
			for (int i = 0; i < 26; i++) {
				ans = max(ans, dp[a][i]);
			}
			for (auto &next : g[a]) {
				for (int i = 0; i < 26; i++) {
					dp[next][i] = max(dp[next][i], dp[a][i]);
				}
				if (--degree[next] == 0) {
					dp[next][colors[next] - 'a']++;
					q.push(next);
				}
			}

		}
		return seen == colors.size() ? ans : -1;
	}
};