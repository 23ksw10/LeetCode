#include <iostream>
#include <vector>
#include <algorithm>





using namespace std;

class Solution {
public:
	int dp[1000];
	int help(vector<int>& arr, int d, int i) {
		if (dp[i] != 0)return dp[i];
		int m = 1;
		for (int k = 1; k <= d; k++) {
			if (i + k < arr.size() && arr[i + k] < arr[i]) {
				m = max(m, 1 + help(arr, d, i + k));
			}
			else break;
		}
		for (int k = 1; k <= d; k++) {
			if (i - k > -1 && arr[i - k] < arr[i]) {
				m = max(m, 1 + help(arr, d, i - k));
			}
			else break;
		}
		return dp[i] = m;
	}
	int maxJumps(vector<int>& arr, int d) {
		int ans = INT_MIN;
		memset(dp, 0, sizeof(dp));
		for (int i = 0; i < arr.size(); i++) {
			ans = max(ans, help(arr, d, i));
		}
		return ans;
	}
};