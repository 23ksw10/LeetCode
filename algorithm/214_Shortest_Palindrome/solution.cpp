#include <iostream>
#include <string>
#include <vector>


using namespace std;


class Solution {
public:
	string shortestPalindrome(string s) {
		if (s.size() < 2)return s;
		string r_s = s;
		reverse(r_s.begin(), r_s.end());
		string t = s + '#' + r_s;
		int i = 1;
		int j = 0;
		vector<int>v(t.size(), 0);
		while (i < t.size()) {
			if (t[i] == t[j]) {
				j++;
				v[i] = j;
				i++;
			}
			else if (j > 0) {
				j = v[j - 1];
			}
			else {
				v[i] = 0;
				i++;
			}
		}
		return r_s.substr(0, s.size() - v[t.size() - 1]) + s;
	}
};