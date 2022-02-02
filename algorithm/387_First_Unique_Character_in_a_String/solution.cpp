#include <iostream>
#include <vector>




using namespace std;


class Solution {
public:
	int firstUniqChar(string s) {
		vector<int>c(26, 0);
		for (auto &a : s) {
			c[a - 'a']++;
		}
		for (int i = 0; i < s.size(); i++) {
			if (c[s[i] - 'a'] == 1)return i;
		}
		return -1;
	}
};