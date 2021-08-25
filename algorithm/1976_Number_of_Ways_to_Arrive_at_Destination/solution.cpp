#include <iostream>
#include <vector>
#include <queue>





using namespace std;


 
 
class Solution {
public:
	int countPaths(int n, vector<vector<int>>& roads) {
		vector<int>dp(n, 0);
		vector<long long>dis(n, LLONG_MAX);
		dis[0] = 0;
		dp[0] = 1;
		vector<vector<pair<int, int>>>g(n);
		for (auto &r : roads) {
			g[r[0]].push_back({ r[1],r[2] });
			g[r[1]].push_back({ r[0],r[2] });
		}
		priority_queue<pair<long long, long long>, vector<pair<long long, long long>>, greater<pair<long long, long long>>>pq;
		pq.push({ 0,0 });
		while (!pq.empty()) {
			auto[cost, d] = pq.top();
			pq.pop();
			for (auto[next, c] : g[d]) {
				if (dis[next] > c + cost) {
					dis[next] = c + cost;
					dp[next] = dp[d];
					pq.push({ c + cost,next });
				}
				else if (dis[next] == c + cost) {
					dp[next] = (dp[next] + dp[d]) % 1000000007;
				}
			}
		}

		return dp[n - 1];
	}
};