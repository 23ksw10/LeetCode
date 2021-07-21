#include <iostream>
#include <vector>
#include <unordered_map>




using namespace std;


 


class Solution {
public:
	string findReplaceString(string s, vector<int>& indices, vector<string>& sources, vector<string>& targets) {
		string ans = "";
		unordered_map<int, pair<string, int>>replace;
		for (int i = 0; i < indices.size(); i++) {
			int k = indices[i];
			int check = 1;
			for (int j = 0; j < sources[i].size(); j++) {
				if (s[k] != sources[i][j]) {
					check = 0;
					break;
				}
				k++;
			}
			if (check) {
				pair<string, int>tmp = { targets[i],sources[i].size() };

				replace[indices[i]] = tmp;
			}

		}
		for (int i = 0; i < s.size(); i++) {
			if (replace.find(i) != replace.end()) {
				ans += replace[i].first;
				i += replace[i].second - 1;
			}
			else ans += s[i];
		}
		return ans;
	}
};