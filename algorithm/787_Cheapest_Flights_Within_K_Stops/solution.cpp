#include <iostream>
#include <vector>
#include <queue>





using namespace std;



class Solution {
public:
	int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int K) {
		vector<vector<pair<int, int>>>v(n);
		for (auto f : flights) {
			v[f[0]].push_back({ f[1],f[2] });
		}
		priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>q;
		q.push({ 0,src,K + 1 });
		while (!q.empty()) {
			auto t = q.top();
			q.pop();
			auto coast = t[0];
			auto s = t[1];
			auto k = t[2];
			if (dst == s) return coast;
			if (k > 0) {
				for (auto i : v[s]) {
					q.push({ coast + i.second,i.first,k - 1 });
				}
			}
		}
		return -1;
	}
};