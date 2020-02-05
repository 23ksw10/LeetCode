#include <iostream>



using namespace std;



class Solution {
public:
	int findComplement(int num) {
		unsigned mask = ~0;
		while (num & mask) mask <<= 1;
		return num ^ ~mask;
	}
};