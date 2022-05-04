#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;


class Solution {
public:
	int maxIceCream(vector<int>& costs, int coins) {
		sort(costs.begin(), costs.end());
		int ans = 0;
		int n = costs.size();
		for (int i = 0; i < n; i++) {
			if (coins - costs[i] >= 0) {
				coins -= costs[i];
				ans++;
			}
		}
		return ans;
	}
};