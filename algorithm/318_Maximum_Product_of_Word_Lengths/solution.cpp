#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <unordered_map>



using namespace std;


class Solution {
public:
	int maxProduct(vector<string>& words) {
		unordered_map<long long, int>m;
		unordered_set<long long>s;
		int n = words.size();
		for (int i = 0; i < n; i++) {
			long long k = 0;
			for (auto &c : words[i]) {
				int alp = c - 'a';
				k |= 1 << alp;
			}
			s.insert(k);
			int size = words[i].size();
			if (m.count(k))m[k] = max(m[k], size);
			else m[k] = words[i].size();
		}
		if (s.size() == 1)return 0;
		vector<long long>v(s.begin(), s.end());
		int ans = 0;
		for (int i = 0; i < v.size(); i++) {
			for (int j = i + 1; j < v.size(); j++) {
				if ((v[i] & v[j]) == 0)ans = max(ans, m[v[i]] * m[v[j]]);
			}
		}
		return ans;
	}
};