#include <iostream>
#include <algorithm>
#include <unordered_map>






using namespace std;




class Solution {
public:
	int balancedString(string s) {
		unordered_map<char, int>m;
		for (auto &c : s) {
			m[c]++;
		}
		int ans = s.size();
		int k = s.size() / 4;
		int l = 0;
		int r = 0;
		for (r; r < s.size(); r++) {
			m[s[r]]--;
			while (l < s.size() && m['Q'] <= k && m['W'] <= k && m['E'] <= k && m['R'] <= k) {
				if (l > r)return 0;
				ans = min(ans, r - l + 1);
				m[s[l]]++;
				l++;
			}
		}
		return ans;
	}
};