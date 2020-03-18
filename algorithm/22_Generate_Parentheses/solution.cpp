#include <iostream>
#include <vector>
#include <string>
using namespace std;


class Solution {
public:
	vector<string> generateParenthesis(int n) {
		vector<string> ans;
		string s;
		help(ans, s, n, 0);

		return ans;
	}
	void help(vector<string> &ans, string s, int n, int a)
	{
		if (n == 0 && a == 0)
		{
			ans.push_back(s);

		}
		if (a)help(ans, s + ")", n, a - 1);
		if (n)help(ans, s + "(", n - 1, a + 1);

	}

};