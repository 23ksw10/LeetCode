#include <iostream>
#include <stack>
#include <string>
using namespace std;


class Solution {
public:
	string reverseOnlyLetters(string S) {
		stack<char> letters;
		string ans;
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] >= 'a'&&S[i] <= 'z')letters.push(S[i]);
			if (S[i] >= 'A'&&S[i] <= 'Z')letters.push(S[i]);
		}
		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] >= 'A'&&S[i] <= 'Z')
			{
				ans.push_back(letters.top());
				letters.pop();
			}
			else if (S[i] >= 'a'&&S[i] <= 'z')
			{
				ans.push_back(letters.top());
				letters.pop();
			}
			else ans.push_back(S[i]);
		}
		return ans;

	}
};
