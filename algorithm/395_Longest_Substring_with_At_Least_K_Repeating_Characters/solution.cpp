#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>





using namespace std;


 
 
class Solution {
public:
	int help(int k, string s, int m) {
		vector<int>dp(26, 0);
		int l = 0;
		int r = 0;
		int uq = 0;
		int count = 0;
		int ans = 0;
		while (r < s.size()) {
			if (!dp[s[r] - 'a'])uq++;
			dp[s[r] - 'a']++;
			if (dp[s[r] - 'a'] == k)count++;
			while (uq > m) {
				dp[s[l] - 'a']--;
				if (dp[s[l] - 'a'] == k - 1) {
					count--;
				}
				if (dp[s[l] - 'a'] == 0) {
					uq--;
				}
				l++;
			}
			if (count == m) {
				ans = max(ans, r - l + 1);
			}
			r++;

		}
		return ans;
	}
	int longestSubstring(string s, int k) {
		unordered_set<int>us;
		for (auto &c : s) {
			us.insert(c);
		}
		int ans = 0;
		for (int i = 1; i <= us.size(); i++) {
			ans = max(ans, help(k, s, i));
		}
		return ans;
	}
};