#include <iostream>
#include <string>




using namespace std;



class Solution {
public:
	int countSubstrings(string s) {
		int len = s.size(), res = len, now = 0;
		while (now < len) {
			int right = now;
			while (s[right] == s[right + 1]) {
				++right;
				res += right - now;
			}
			int left = now - 1;
			++right;
			now = right;
			while (left >= 0 && right < len && s[left] == s[right]) {
				--left;
				++right;
				++res;
			}
		}

		return res;
	}
};