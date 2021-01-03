#include <iostream>
#include <vector>
#include <unordered_map>
#include <queue>





using namespace std;



class Solution {
public:

	vector<string> topKFrequent(vector<string>& words, int k) {
		struct compare {
			bool operator()(pair<int, string>a, pair<int, string>b) {
				return a.first < b.first || (a.first == b.first&&a.second > b.second);
			}
		};
		vector<string>ans;
		unordered_map<string, int>m;
		priority_queue<pair<int, string>, vector<pair<int, string>>, compare>pq;
		for (auto &w : words) {
			m[w]++;
		}
		for (auto it = m.begin(); it != m.end(); it++) {
			auto a = make_pair(it->second, it->first);
			pq.push(a);

		}
		while (ans.size() != k) {
			ans.push_back(pq.top().second);
			pq.pop();
		}
		return ans;

	}
};