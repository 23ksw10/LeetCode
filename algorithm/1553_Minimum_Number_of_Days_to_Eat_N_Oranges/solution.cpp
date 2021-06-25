#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>


using namespace std;


 

class Solution {
public:
	unordered_map<int, int>dp;
	int minDays(int n) {
		if (n <= 1)return n;
		if (!dp.count(n)) {
			dp[n] = min(1 + n % 2 + minDays(n / 2), 1 + n % 3 + minDays(n / 3));
		}
		return dp[n];
	}
};