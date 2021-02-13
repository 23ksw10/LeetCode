#include <iostream>
#include <vector>
#include <unordered_set>



using namespace std;

class Solution {
public:
	string minWindow(string s, string t) {
		string ans = "";
		vector<int>m(128, 0);
		vector<int>window(128, 0);
		unordered_set<char>st;
		for (auto &c : t) {
			m[c]++;
			st.insert(c);
		}
		int j = 0;
		int have = 0;
		for (int i = 0; i < s.size(); i++) {
			window[s[i]]++;
			if (m[s[i]] != 0 && m[s[i]] == window[s[i]]) {
				have++;
			}
			while (have == st.size()) {
				if (ans.size() == 0 || i - j + 1 < ans.size())ans = s.substr(j, i - j + 1);

				window[s[j]]--;
				if (m[s[j]] != 0 && m[s[j]] > window[s[j]]) {
					have--;
				}
				j++;
			}

		}

		return ans;
	}
};