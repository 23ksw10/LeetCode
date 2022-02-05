#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>


using namespace std;

class Solution {
public:
	int maxSumMinProduct(vector<int>& nums) {
		long long ans = 0;
		long long m = 1e9 + 7;
		vector<long long>dp(nums.size(), 0);
		dp[0] = nums[0];
		for (int i = 1; i < nums.size(); i++) {
			dp[i] = dp[i - 1] + nums[i];
		}
		stack<pair<int, int>>s;
		nums.push_back(0);
		for (int i = 0; i < nums.size(); i++) {
			int index = i;
			while (!s.empty() && s.top().first >= nums[i]) {
				index = s.top().second;


				long long tmp = (long long)s.top().first* (dp[i - 1] - (index == 0 ? 0 : dp[index - 1]));
				ans = max(ans, tmp);

				s.pop();
			}
			s.push({ nums[i],index });
		}
		return ans % m;
	}
};