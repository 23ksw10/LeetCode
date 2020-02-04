#include <iostream>
#include <string>


using namespace std;



class Solution {
public:
	string toLowerCase(string str) {
		for (int i = 0; i < str.size(); i++)
		{
			if (65 <= str[i] && str[i] < 91)
			{
				str[i] += 32;
			}
		}
		return str;

	}
};


