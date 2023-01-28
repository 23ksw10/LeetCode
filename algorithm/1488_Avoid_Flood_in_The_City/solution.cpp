#include <iostream>
#include <vector>
#include <map>
#include <set>


using namespace std;


class Solution {
public:
	vector<int> avoidFlood(vector<int>& rains) {
		int n = rains.size();
		vector<int>ans(n);
		map<int, int>m;
		set<int>dry;
		for (int i = 0; i < n; i++) {
			int r = rains[i];
			if (r > 0) {
				if (m.find(r) == m.end()) {
					m[r] = i;
					ans[i] = -1;
				}
				else {
					if (dry.size() == 0) {
						return {};
					}
					else {
						auto it = dry.lower_bound(m[r]);
						if (it == dry.end())return {};
						int k = *it;
						ans[k] = r;
						dry.erase(k);
						m[r] = i;
						ans[i] = -1;
					}
				}
			}
			else {
				dry.insert(i);
				ans[i] = 1;
			}
		}

		return ans;
	}
};

