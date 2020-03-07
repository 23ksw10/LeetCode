#include <iostream>

using namespace std;


class Solution {
public:
	bool hasAlternatingBits(int n) {
		int pbit = 1;
		pbit = pbit & n;
		n = n >> 1;
		int nbit = 1;
		nbit = nbit & n;
		while (pbit^nbit&&n)
		{
			pbit = nbit;
			n = n >> 1;
			nbit = n & 1;
		}
		return pbit ^ nbit;
	}
};