#include <iostream>


using namespace std;

class Solution {
public:
	int hammingDistance(int x, int y) {
		int ans = 0;
		int count = 0;
		int t = (x > y ? x : y);
		int m = x ^ y;
		while (t)
		{

			t /= 2;
			count++;
		}
		while (count)
		{
			if (m % 2 == 1)
			{
				ans++;
			}
			m /= 2;
			count--;
		}
		return ans;
	}
};
