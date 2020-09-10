#include <iostream>
#include <vector>
#include <string>
#include <algorithm>








using namespace std;




class Solution {
public:
	vector<string> printVertically(string s) {
		vector<string>ans;
		vector<string>words;
		string temp;
		int max_len = 0;
		for (auto c : s) {
			if (c == ' ') {
				words.push_back(temp);
				int size = temp.size();
				max_len = max(max_len, size);
				temp = "";

			}
			else temp += c;
		}
		int size = temp.size();
		max_len = max(max_len, size);
		words.push_back(temp);
		for (int k = 0; k < max_len; k++) {
			string tmp;
			for (int i = 0; i < words.size(); i++) {
				if (k >= words[i].size()) tmp.push_back(' ');
				else tmp.push_back(words[i][k]);
			}
			int l = tmp.size() - 1;
			while (tmp[l] == ' ') {
				l--;
			}
			tmp = tmp.substr(0, l + 1);
			ans.push_back(tmp);
		}
		return ans;
	}
	
};
