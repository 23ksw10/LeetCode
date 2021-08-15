#include <iostream>





using namespace std;


 
 
class Solution {
public:
	int concatenatedBinary(int n) {
		int mod = 1000000007;
		long result = 0, length = 0;
		for (int i = 1; i <= n; i++)
		{
			if ((i&(i - 1)) == 0)
			{
				length++;
			}
			result = ((result << length) + i) % mod;
		}
		return result;
	}
};
};