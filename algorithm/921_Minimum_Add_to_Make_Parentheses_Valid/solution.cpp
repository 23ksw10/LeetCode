#include <iostream>
#include <string>


using namespace std;



class Solution {
public:
	int minAddToMakeValid(string S) {
		int right = 0;
		int left = 0;
		for (auto c : S)
		{
			if (c == '(')
				right++;
			else
				if (right)
					right--;
				else
					left++;
		}
		return right + left;

	}
};