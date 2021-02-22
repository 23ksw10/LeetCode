#include <iostream>
#include <unordered_set>
#include <algorithm>
#include <string>



using namespace std;

class Solution {
public:
	bool checkInclusion(string s1, string s2) {
		vector<int>alp(26, 0);
		vector<int>alp2(26, 0);
		int count = 0;
		unordered_set<int>s;
		int ans = INT_MAX;
		for (auto &a : s1) {
			alp[a - 'a']++;
			s.insert(a);
		}
		int l = 0;
		int k = s.size();
		for (int r = 0; r < s2.size(); r++) {
			int i = s2[r] - 'a';
			alp2[i]++;
			if (alp2[i] == alp[i] && alp[i]) count++;
			while (l < s2.size() && count >= k) {
				ans = min(ans, r - l + 1);
				if (ans == s1.size())return true;
				int j = s2[l] - 'a';
				alp2[j]--;
				if (alp2[j] < alp[j] && alp[j])count--;
				l++;
			}

		}
		return false;
	}
};