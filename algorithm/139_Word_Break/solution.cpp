#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


using namespace std;

class Solution {
public:
	unordered_map<string, bool>m;
	bool wordBreak(string s, vector<string>& wordDict) {
		if (m.find(s) != m.end())return m[s];
		for (auto w : wordDict) {
			if (s.find(w) == 0) {
				if (w == s)return true;
				if (!wordBreak(s.substr(w.size()), wordDict)) {
					m[s] = false;
					continue;
				}
				else return true;
			}
		}
		m[s] = false;
		return false;
	}
};