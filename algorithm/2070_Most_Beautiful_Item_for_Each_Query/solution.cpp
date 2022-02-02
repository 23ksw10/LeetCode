#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>



using namespace std;


class Solution {
public:
	vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
		sort(items.begin(), items.end());
		vector<int>q = queries;
		sort(q.begin(), q.end());
		unordered_map<int, int>mp;
		int n = items.size();
		int m = queries.size();
		vector<int>ans(m, 0);
		int l = 0;
		int mx = 0;
		for (int i = 0; i < m; i++) {
			while (l < n&&items[l][0] <= q[i]) {
				mx = max(mx, items[l][1]);
				l++;
			}
			mp[q[i]] = mx;
		}
		for (int i = 0; i < m; i++) {
			ans[i] = mp[queries[i]];
		}
		return ans;
	}
};