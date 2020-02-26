#include <iostream>
#include <string>
#include <vector>


using namespace std;


class Solution {
public:
	vector<int> shortestToChar(string S, char C) {
		vector<int> ans;
		vector<int> CharLocation;

		for (int i = 0; i < S.size(); i++)
		{
			if (S[i] == C) CharLocation.push_back(i);

		}
		if (CharLocation.size() == 1)
		{
			for (int i = 0; i < S.size(); i++)
			{
				int d = abs(CharLocation[0] - i);

				ans.push_back(d);

			}
			return ans;


		}
		int j = 0;
		for (int i = 0; i < S.size(); i++)
		{

			int d1 = abs(i - CharLocation[j]);
			int d2 = abs(i - CharLocation[j + 1]);
			if (d1 < d2)
			{
				ans.push_back(d1);
			}
			if (d1 >= d2)
			{
				ans.push_back(d2);
			}
			if (d2 == 0 && j + 1 < CharLocation.size() - 1)
			{
				j++;
			}
		}
		return ans;

	}
};