#include <iostream>
#include <string>

using namespace std;



class Solution {
public:
	char findTheDifference(string s, string t) {
		char ans;
		for (int i = 'a'; i <= 'z'; i++)
		{
			int cnt = count(s.begin(), s.end(), i);
			int snt = count(t.begin(), t.end(), i);
			if (snt > cnt)
				ans = i;
		}
		return ans;
	}
};