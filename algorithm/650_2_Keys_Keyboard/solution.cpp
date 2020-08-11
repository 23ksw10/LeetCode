#include <iostream>



using namespace std;



class Solution {
public:
	int minSteps(int n) {
		if (n == 1)return 0;
		if (n % 2) {
			int gcd = 0;
			for (int i = 1; i < n / 2 + 1; i++) {
				if (n%i == 0)gcd = i;
			}
			return minSteps(gcd) + n / gcd;
		}
		else {
			return minSteps(n / 2) + 2;
		}
	}
};