#include <iostream>
#include <vector>
#include <queue>





using namespace std;


 

class Solution {
public:
	vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {

		if (n == 1)return{ 0 };
		if (n == 2)return edges[0];
		vector<int>ans;
		vector<vector<int>>g(n);
		vector<int>d(n, 0);
		int k = n;
		for (auto &e : edges) {
			g[e[0]].push_back(e[1]);
			g[e[1]].push_back(e[0]);
			d[e[0]]++;
			d[e[1]]++;
		}
		queue<int>q;
		for (int i = 0; i < n; i++) {
			if (d[i] == 1)q.push(i);
		}
		while (n > 2) {
			int s = q.size();
			n -= s;
			for (int i = 0; i < s; i++) {
				auto a = q.front();
				q.pop();
				d[a]--;
				for (auto &b : g[a]) {

					d[b]--;
					if (d[b] == 1)q.push(b);

				}
			}
		}
		while (q.size()) {
			auto a = q.front();
			q.pop();
			ans.push_back(a);
		}
		return ans;
	}
};
};