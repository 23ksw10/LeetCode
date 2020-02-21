#include <iostream>
#include <vector>
#include <string>
#include <map>



using namespace std;


class Solution {
public:
	string customSortString(string S, string T) {
		vector<char> sOrder;
		map<char, int>m;
		string ans;
		for (int i = 0; i < S.size(); i++)
		{
			sOrder.push_back(S[i]);
		}
		for (int i = 0; i < T.size(); i++)
		{
			++m[T[i]];
		}
		for (int i = 0; i < sOrder.size(); i++)
		{
			for (int j = 0; j < m[sOrder[i]]; j++)
			{
				ans.push_back(sOrder[i]);
			}
			m[sOrder[i]] = 0;

		}
		auto it = m.begin();
		for (it; it != m.end(); it++)
		{
			if (it->second > 0)
				for (int i = 0; i < it->second; i++)
				{
					ans.push_back(it->first);
				}
		}
		return ans;
	}
};
