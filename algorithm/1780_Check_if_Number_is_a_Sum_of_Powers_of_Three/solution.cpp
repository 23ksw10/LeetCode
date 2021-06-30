#include <iostream>




using namespace std;


 


class Solution {
public:
	bool checkPowersOfThree(int n) {
		long long t = 1;
		long long a = 1;
		while (n >= 3) {
			while (t <= n) {
				t *= 3;
			}
			t /= 3;
			n -= t;
			if (a == t)return false;
			a = t;
			t = 1;
		}
		return n == 0 || n == 1;
	}
};