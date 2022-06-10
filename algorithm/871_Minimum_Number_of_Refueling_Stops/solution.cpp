#include <iostream>
#include <vector>
#include <queue>




using namespace std;


class Solution {
public:
	int minRefuelStops(int target, int startFuel, vector<vector<int>>& stations) {
		priority_queue<int>pq;
		int ans = 0;
		int last = 0;
		stations.push_back({ target,0 });
		for (auto &station : stations) {
			startFuel -= station[0] - last;
			while (!pq.empty() && startFuel < 0) {
				startFuel += pq.top();
				ans++;
				pq.pop();
			}
			if (startFuel < 0)return -1;
			pq.push(station[1]);
			last = station[0];
		}
		return ans;
	}
};