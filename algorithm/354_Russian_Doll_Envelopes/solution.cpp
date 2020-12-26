#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;



class Solution {
public:
	int maxEnvelopes(vector<vector<int>>& envelopes) {
		if (!envelopes.size())return 0;
		sort(envelopes.begin(), envelopes.end(), [](auto &a, auto &b) {return a[0] < b[0] || (a[0] == b[0] && a[1] > b[1]); });
		int n = envelopes.size();
		vector<int>d;
		d.push_back(envelopes[0][1]);
		int ans = 1;
		for (int i = 1; i < n; i++) {
			int a = envelopes[i][1];
			auto it = lower_bound(d.begin(), d.end(), a);
			if (it == d.end())d.push_back(a);
			else *it = a;

		}

		return d.size();
	}
};