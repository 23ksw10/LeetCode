#include <iostream>
#include <vector>



using namespace std;



class Solution {
public:
	void reverseString(vector<char>& s) {
		char a;

		for (int i = 0; i < s.size() / 2; i++)
		{
			a = s[i];
			int change = s.size() - i;
			s[i] = s[change];
			s[change] = a;
		}

	}
};