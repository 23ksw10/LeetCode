#include <iostream>
#include <string>
using namespace std;



class Solution {
public:
	int subtractProductAndSum(int n) {
		int add = 0;
		int mul = 1;
		while (!(n / 10 == 0))
		{
			add += n % 10;
			mul *= n % 10;

			n /= 10;
		}
		add += n;
		mul *= n;
		return mul - add;

	}
};