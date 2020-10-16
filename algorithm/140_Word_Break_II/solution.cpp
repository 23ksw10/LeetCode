#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>


using namespace std;

class Solution {
public:
	unordered_map<string, vector<string>>m;
	vector<string> wordBreak(string s, vector<string>& wordDict) {
		if (m.find(s) != m.end())return m[s];
		vector<string>ans;
		for (auto w : wordDict) {
			if (s.find(w) == 0) {
				if (s == w)ans.push_back(w);
				else {
					vector<string>tmp = wordBreak(s.substr(w.size()), wordDict);
					for (auto t : tmp) {
						ans.push_back(w + ' ' + t);
					}
				}
			}
		}
		m[s] = ans;
		return ans;
	}
};