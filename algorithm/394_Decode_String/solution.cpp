#include <iostream>
#include <string>





using namespace std;


class Solution {
public:
	string decodeString(string s) {
		string ans;
		int count = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] - '0' >= 0 && s[i] - '0' <= 9) {
				int m = s[i] - '0';
				for (int l = i + 1; l < s.size(); l++) {
					if (s[l] - '0' >= 0 && s[l] - '0' <= 9) {
						m *= 10;
						m += s[l] - '0';
					}
					else {
						i = l - 1;
						break;
					}
				}
				string tmp;
				for (int j = i + 1; j < s.size(); j++) {
					if (s[j] == '[')count++;
					if (s[j] == ']')count--;
					if (count == 0) {
						tmp = decodeString(s.substr(i + 2, j - i - 2));
						i = j;
						break;
					}
				}
				for (int k = 0; k < m; k++) {
					ans += tmp;
				}
			}
			else ans += s[i];
		}
		return ans;
	}
};