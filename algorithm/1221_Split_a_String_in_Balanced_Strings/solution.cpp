#include <iostream>
#include <string>

using namespace std;



class Solution {
public:
	int balancedStringSplit(string s) {
		int Rcount = 0;
		int Lcount = 0;
		int ans = 0;
		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == 'R')
				Rcount++;
			if (s[i] == 'L')
			{
				Lcount++;
			}
			if (Rcount == Lcount)
				ans++;
		}
		return ans;
	}
};

