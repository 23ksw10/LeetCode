#include <iostream>
#include <vector>
#include <string>
#include <queue>



using namespace std;



class Solution {
public:

	bool isPredecessor(string &word1, string &word2) {
		int i = 0, j = 0;
		while (i < word1.size() && j < word2.size()) {
			i += (word1[i] == word2[j]);
			j++;
			if (j - i >= 2)return 0;
		}
		return 1;
	}

	int longestStrChain(vector<string>& words) {
		vector<vector<pair<string, int>>> wbyl(16);
		for (auto w : words) {
			wbyl[w.size() - 1].push_back({ w,1 });
		}
		int res = 1;
		for (int i = 14; i >= 0; i--) {
			for (auto &w1 : wbyl[i]) {
				for (auto &w2 : wbyl[i + 1]) {
					if (isPredecessor(w1.first, w2.first)) {
						w1.second = max(w1.second, w2.second + 1);
						res = max(res, w1.second);
					}
				}
			}
		}
		return res;
	}
};