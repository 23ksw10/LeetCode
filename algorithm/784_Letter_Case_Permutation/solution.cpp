#include <iostream>
#include <vector>
#include <string>



using namespace std;



class Solution {
public:
	vector<string> letterCasePermutation(string S) {
		vector<string> ans;


		letterChange(ans, S, 0);

		return ans;

	}
	void letterChange(vector<string> &ans, string s, int index)
	{
		if (index < s.size())
		{
			ans.push_back(s);
			for (int i = index; i < s.size(); i++)
			{
				if (s[i] >= 97 && s[i] <= 122)
				{
					s[i] -= 32;
					letterChange(ans, s, i + 1);
					s[i] += 32;
				}
				if (s[i] >= 65 && s[i] <= 90)
				{
					s[i] += 32;
					letterChange(ans, s, index + 1);
					s[i] -= 32;
				}

			}


		}
	}
};