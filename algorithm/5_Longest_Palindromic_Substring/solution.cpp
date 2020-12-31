#include <iostream>
#include <string>
#include <algorithm>




using namespace std;



class Solution {
public:
	string longestPalindrome(string s) {
		int n = s.size();
		int len = 0;
		int start = 0, end = 0;
		for (int k = 0; k < n; k++) {
			int i = k, j = k;
			while (i >= 0 && j < n && s[i] == s[j]) {
				i--;
				j++;
			}
			len = max(j - i - 1, len);

			i = k, j = k + 1;
			while (i >= 0 && j < n && s[i] == s[j]) {
				i--;
				j++;
			}
			len = max(j - i - 1, len);

			if (len > end - start + 1) {
				start = k - (len - 1) / 2;
				end = k + len / 2;
			}
		}
		return s.substr(start, end - start + 1);
	}
};