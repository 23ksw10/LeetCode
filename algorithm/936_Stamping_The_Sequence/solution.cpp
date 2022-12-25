#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	vector<int> movesToStamp(string stamp, string target) {
		int n = stamp.size();
		int m = target.size();
		vector<int>ans;
		vector<int>check(m - n + 1);
		bool ok = true;
		while (ok) {
			ok = false;
			for (int i = 0; i <= m - n; i++) {
				if (check[i])continue;
				int j = 0;
				for (j; j < n; j++) {
					if (target[i + j] == '*')continue;
					if (target[j + i] != stamp[j])break;
				}
				if (j == n) {
					ans.push_back(i);
					check[i] = 1;
					for (int j = 0; j < n; j++) {
						target[j + i] = '*';
					}
					ok = true;
				}
			}
		}
		for (auto t : target) {
			if (t != '*')return {};
		}
		reverse(ans.begin(), ans.end());
		return ans;
	}
};

