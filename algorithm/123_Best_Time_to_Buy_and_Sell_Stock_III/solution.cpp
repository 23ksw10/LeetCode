#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

class Solution {
public:
	int maxProfit(vector<int>& prices) {

		int n = prices.size();
		vector<int>l(n);
		vector<int>r(n);
		int min_prices = 500000; int profit = 0;
		for (int i = 0; i < n; i++) {
			min_prices = min(min_prices, prices[i]);
			profit = max(profit, prices[i] - min_prices);
			l[i] = (profit);
		}
		int max_price = 0;
		profit = 0;
		for (int i = n - 1; i >= 0; i--) {
			max_price = max(max_price, prices[i]);
			profit = max(profit, max_price - prices[i]);
			r[i] = (profit);
		}

		int ans = 0;
		for (int i = 0; i < n; i++) {
			ans = max(ans, l[i] + r[i]);
		}
		return ans;
	}
};