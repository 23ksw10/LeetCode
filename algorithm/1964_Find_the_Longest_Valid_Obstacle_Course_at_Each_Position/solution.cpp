#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;


 
 
class Solution {
public:
	vector<int> longestObstacleCourseAtEachPosition(vector<int>& obstacles) {
		vector<int>ans;
		vector<int>dp;
		dp.push_back(obstacles[0]);
		ans.push_back(1);
		for (int i = 1; i < obstacles.size(); i++) {
			if (obstacles[i] >= dp.back()) {
				dp.push_back(obstacles[i]);
				ans.push_back(dp.size());
			}
			else {
				auto it = upper_bound(dp.begin(), dp.end(), obstacles[i]) - dp.begin();
				dp[it] = obstacles[i];
				ans.push_back(it + 1);
			}
		}
		return ans;
	}
};