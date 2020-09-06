#include <iostream>
#include <vector>
#include <string>
#include <algorithm>








using namespace std;




class Solution {
public:
	int minCost(string s, vector<int>& cost) {
		int ans = 0;
		int m = 0;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] != s[i - 1]) {
				m = 0;
				continue;
			}
			if (!m) {

				m = max(cost[i], cost[i - 1]);
				ans += min(cost[i], cost[i - 1]);

			}
			else {
				if (cost[i] < m)ans += cost[i];
				else {
					ans += m;
					m = cost[i];
				}
			}
		}
		return ans;
	}
};