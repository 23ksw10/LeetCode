#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



class Solution {
public:
	int bestTeamScore(vector<int>& scores, vector<int>& ages) {
		int ans = 0;
		vector<pair<int, int>>v;
		int s = scores.size();
		for (int i = 0; i < s; i++) {
			v.push_back({ ages[i],scores[i] });
		}
		sort(v.begin(), v.end());
		vector<int>dp(s, 0);
		for (int i = 0; i < s; i++) {
			int score = v[i].second;
			dp[i] = score;
			for (int j = 0; j < i; j++) {
				if (v[i].first == v[j].first)dp[i] = max(dp[i], dp[j] + score);
				else if (score >= v[j].second)dp[i] = max(dp[i], dp[j] + score);
			}
			ans = max(ans, dp[i]);
		}
		return ans;

	}
};