#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <unordered_map>




using namespace std;


 

class Solution {
public:
	vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
		vector<int>ans;
		sort(intervals.begin(), intervals.end());
		vector<int>tmp = queries;
		sort(queries.begin(), queries.end());
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>>pq;
		unordered_map<int, int>m;
		int i = 0;
		for (auto &q : queries) {
			while (i < intervals.size() && intervals[i][0] <= q) {
				pq.push({ intervals[i][1] - intervals[i][0] + 1,intervals[i][1] });
				i++;
			}

			while (!pq.empty()) {
				if (pq.top().second < q)pq.pop();
				else {
					m[q] = pq.top().first;
					break;
				}
			}
		}
		for (auto &t : tmp) {
			if (!m.count(t))ans.push_back(-1);
			else ans.push_back(m[t]);
		}
		return ans;
	}
};