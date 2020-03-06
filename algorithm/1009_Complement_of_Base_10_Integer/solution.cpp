#include <iostream>



using namespace std;


class Solution {
public:
	int bitwiseComplement(int N) {
		int bit = 1;
		while (bit < N)
		{
			bit = (bit << 1) + 1;
		}
		return N ^ bit;

	}
};