#include <iostream>
#include <vector>
#include <map>
#include <algorithm>


using namespace std;


class Solution {
public:
	vector<int> smallestRange(vector<vector<int>>& nums) {
		vector<int>ans;
		vector<pair<int, int>>v;
		for (int i = 0; i < nums.size(); i++) {
			for (int j = 0; j < nums[i].size(); j++) {
				v.push_back({ nums[i][j],i });
			}
		}
		sort(v.begin(), v.end());

		int n = v.size();
		int l = 0;
		int k = 0;
		map<int, int>m;
		for (int r = 0; r < n; r++) {
			if (!m[v[r].second]) {
				k++;
			}
			m[v[r].second]++;
			if (k == nums.size()) {
				while (m[v[l].second] > 1) {
					m[v[l].second]--;
					l++;
				}
				if (!ans.size() || ans[1] - ans[0] > v[r].first - v[l].first) {
					ans = vector<int>{ v[l].first,v[r].first };
				}
			}
		}
		return ans;
	}
};