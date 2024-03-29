#include <iostream>
#include <string>
#include <algorithm>



using namespace std;

class Solution {
public:
	string orderlyQueue(string s, int k) {
		if (k == 1) {
			string ans = s;
			for (int i = 0; i < s.size(); i++) {
				ans = min(ans, s.substr(i) + s.substr(0, i));
			}
			return ans;
		}
		sort(s.begin(), s.end());
		return s;
	}
};

