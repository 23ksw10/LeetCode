#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;

class Solution {
public:
	int numMatchingSubseq(string s, vector<string>& words) {
		int ans = 0;
		vector<vector<int>>v(26);
		for (int i = 0; i < s.size(); i++) {
			v[s[i] - 'a'].push_back(i);
		}
		for (auto &w : words) {
			int x = -1;
			bool find = true;
			for (auto &c : w) {
				auto it = upper_bound(v[c - 'a'].begin(), v[c - 'a'].end(), x);
				if (it == v[c - 'a'].end()) {
					find = false;
					break;
				}
				x = *it;
			}
			if (find)ans++;
		}
		return ans;
	}
};