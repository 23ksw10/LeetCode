#include <iostream>
#include <string>



using namespace std;

class Solution {
public:
	bool validPalindrome(string s) {
		int l = 0;
		int r = s.size() - 1;
		while (l <= r) {
			if (s[l] == s[r]) {
				l++;
				r--;
			}
			else {
				if (help(s.substr(l, r - l))) return true;
				else if (help(s.substr(l + 1, r - l)))return true;
				else return false;


			}
		}
		return true;
	}
	bool help(string s) {
		int l = 0;
		int r = s.size() - 1;
		while (l <= r) {
			if (s[l] == s[r]) {
				l++;
				r--;
			}
			else return false;
		}
		return true;
	}
};