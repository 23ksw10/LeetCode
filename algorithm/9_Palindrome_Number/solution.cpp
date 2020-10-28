#include <iostream>






using namespace std;


class Solution {
public:
	bool isPalindrome(int x) {
		if (x < 0)return false;
		long long a = 0;
		int t = x;
		while (t) {
			a = a * 10 + t % 10;
			t /= 10;
		}
		cout << a;
		if (a != x)return false;
		return true;
	}
};