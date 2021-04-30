#include <iostream>
#include <vector>
#include <queue>

using namespace std;


 

class Solution {
public:
	int networkDelayTime(vector<vector<int>>& times, int n, int k) {
		int ans = -1;
		vector<int>visit(n + 1, 0);
		visit[k] = 1;
		vector<pair<int, int>>network[n + 1];
		for (auto &a : times) {
			network[a[0]].push_back({ -a[2],a[1] });
		}
		priority_queue<pair<int, int>, vector<pair<int, int>>>pq;
		for (int i = 0; i < network[k].size(); i++) {
			pq.push(network[k][i]);
		}
		while (!pq.empty()) {
			auto a = pq.top();
			pq.pop();
			if (visit[a.second])continue;
			ans = -a.first;
			visit[a.second] = 1;
			for (int i = 0; i < network[a.second].size(); i++) {
				auto k = network[a.second][i];
				k.first += a.first;
				if (visit[k.second])continue;
				pq.push(k);
			}
		}

		for (int i = 1; i < visit.size(); i++) {
			if (!visit[i]) return -1;
		}
		return ans;
	}
};