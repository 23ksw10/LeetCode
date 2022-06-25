#include <iostream>
#include <string>
#include <algorithm>


using namespace std;


class Solution {
public:
	int minFlips(string s) {
		int ans = INT_MAX;
		string zero = "";
		string one = "";
		int n = s.size();
		s = s + s;
		for (int i = 0; i < 2 * n; i++) {
			if (i % 2 == 0) {
				zero += '0';
				one += '1';
			}
			else {
				zero += '1';
				one += '0';
			}
		}
		int z_diff = 0;
		int o_diff = 0;
		for (int i = 0; i < n; i++) {
			if (s[i] != zero[i]) {
				z_diff++;
			}
			if (s[i] != one[i]) {
				o_diff++;
			}
		}
		ans = min(z_diff, o_diff);
		for (int i = n; i < 2 * n; i++) {
			if (s[i - n] != zero[i - n]) {
				z_diff--;
			}
			if (s[i] != zero[i]) {
				z_diff++;
			}
			if (s[i - n] != one[i - n]) {
				o_diff--;
			}
			if (s[i] != one[i]) {
				o_diff++;
			}
			ans = min({ ans,o_diff,z_diff });
		}
		return ans;
	}
};