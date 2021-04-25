#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;


 
class Solution {
public:
	vector<int> getOrder(vector<vector<int>>& tasks) {
		vector<int>ans;
		priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>>pq;
		for (int i = 0; i < tasks.size(); i++) {
			tasks[i].push_back(i);
		}
		sort(tasks.begin(), tasks.end());
		int time = tasks[0][0];
		for (int i = 0; i < tasks.size();) {
			if (tasks[i][0] <= time) {
				pq.push({ tasks[i][1],tasks[i][2] });
				i++;
			}
			else {
				if (!pq.size()) {
					pq.push({ tasks[i][1],tasks[i][2] });
					time = tasks[i][0];
					i++;
					continue;
				}
				auto a = pq.top();
				pq.pop();
				ans.push_back(a.second);
				time += a.first;
			}
		}
		while (pq.size()) {
			auto a = pq.top();
			pq.pop();
			ans.push_back(a.second);
		}
		return ans;
	}
};