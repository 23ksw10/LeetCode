#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;


 

class Solution {
public:
	int getMaximumConsecutive(vector<int>& coins) {
		int ans = 0;
		sort(coins.begin(), coins.end());
		int n = coins.size();
		for (int i = 0; i < n; i++) {
			if (ans + 1 < coins[i])break;
			ans += coins[i];
		}
		return ans + 1;
	}
};