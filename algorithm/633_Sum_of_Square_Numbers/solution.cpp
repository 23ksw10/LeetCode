#include <iostream>


using namespace std;


class Solution {
public:
	long long help(int c) {
		long long a = 1;
		long long x = 1;
		while (x <= c) {
			a = a + 1;
			x = a * a;
		}
		return a;
	}
	bool judgeSquareSum(int c) {
		long long r = help(c);
		int l = 0;
		while (l <= r) {
			long long sum = 0;
			long long left = l * l;
			long long right = r * r;
			sum = left + right;
			if (sum == c)return true;
			if (sum < c)l++;
			else r--;
		}
		return false;
	}
};