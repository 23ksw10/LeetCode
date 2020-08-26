#include <iostream>
#include <vector>
#include <algorithm>






using namespace std;




class Solution {
public:
	int maxSatisfaction(vector<int>& satisfaction) {
		sort(satisfaction.begin(), satisfaction.end());
		int n = satisfaction.size();
		int ans = 0;
		int tmp = 0;
		for (int i = n - 1; i >= 0 && satisfaction[i] > -tmp; i--) {
			tmp += satisfaction[i];
			ans += tmp;
		}

		return ans;
	}
};