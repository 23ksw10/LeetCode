#include <iostream>






using namespace std;



class Solution {
public:
	int rangeBitwiseAnd(int m, int n) {
		long count = 1;
		if (!m)return 0;



		while (m != n) {
			m = m >> 1;
			n = n >> 1;
			count *= 2;
		}
		return m * count;




	}
};