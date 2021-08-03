#include <iostream>
#include <vector>
#include <queue>




using namespace std;


 

class Solution {
public:
	int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
		int n = passingFees.size();
		vector<vector<pair<int, int>>>g(n);
		for (auto &e : edges) {
			int a = e[0];
			int b = e[1];
			int c = e[2];
			g[a].push_back({ b,c });
			g[b].push_back({ a,c });
		}
		vector<int>times(n, INT_MAX);
		priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>>pq;
		for (auto &a : g[0]) {
			if (a.second > maxTime)continue;
			pq.push({ passingFees[0] + passingFees[a.first],a.second,a.first });
		}
		times[0] = 0;
		while (!pq.empty()) {
			auto[cost, time, d] = pq.top();
			pq.pop();
			if (d == n - 1)return cost;
			for (auto &b : g[d]) {
				if (times[b.first] > time + b.second&&time + b.second <= maxTime) {
					times[b.first] = time + b.second;
					pq.push({ cost + passingFees[b.first],time + b.second,b.first });
				}
			}

		}

		return -1;
	}
};