#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



class Solution {
public:
	int numTimesAllBlue(vector<int>& light) {
		int ans = 0;
		int now = 0;

		for (int i = 0; i < light.size(); i++)
		{
			now = max(now, light[i]);
			if (now == i + 1) ans++;
		}


		return ans;
	}
};