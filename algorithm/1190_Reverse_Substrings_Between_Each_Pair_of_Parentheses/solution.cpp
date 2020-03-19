#include <iostream>
#include <stack>
#include <algorithm>
#include <string>

using namespace std;



class Solution {
public:
	string reverseParentheses(string s) {
		stack< int> stack;
		int l = 0;
		int r = s.size() - 1;

		for (int i = 0; i < s.size(); i++)
		{
			if (s[i] == '(')
			{
				stack.push(i);

			}

			if (s[i] == ')')
			{
				auto it = stack.top();
				reverse(s.begin() + it, s.begin() + i + 1);
			}

		}
		for (int i = 0; i < s.size();)
		{
			if (s[i] == '(' || s[i] == ')')
				s.erase(s.begin() + i);
			else i++;
		}

		return s;

	}
}