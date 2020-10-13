#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

class Solution {
public:
	int minCostClimbingStairs(vector<int>& cost) {
		int d1 = 0;
		int d2 = 0;
		for (int i = 2; i <= cost.size(); i++) {
			int tmp = d1;
			d1 = d2;
			d2 = min(tmp + cost[i - 2], d2 + cost[i - 1]);

		}
		return d2;
	}
};