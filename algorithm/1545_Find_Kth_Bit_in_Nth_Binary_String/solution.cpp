#include <iostream>
#include <string>



using namespace std;

class Solution {
public:
	char findKthBit(int n, int k) {
		string s = "0";
		for (int i = 2; i <= n; i++) {
			string tmp;
			for (int j = s.size() - 1; j >= 0; j--) {
				if (s[j] == '0') tmp.push_back('1');
				else tmp.push_back('0');
			}
			s = s + "1" + tmp;

		}
		return s[k - 1];
	}

};