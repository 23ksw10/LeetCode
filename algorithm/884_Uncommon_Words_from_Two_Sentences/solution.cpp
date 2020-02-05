#include <iostream>
#include <vector>
#include<map>


using namespace std;



class Solution {
public:
	vector<string> uncommonFromSentences(string A, string B) {
		map<string, int>m;
		vector<string> ans;
		int Astart = 0;
		int Bstart = 0;
		for (int i = 0; i < A.size(); i++)
		{
			string a;

			if (A[i] == ' ' || i == A.size() - 1)
			{
				if (i != A.size() - 1)
				{
					for (int j = Astart; j < i; j++)
						a.push_back(A[j]);
				}
				else
				{
					for (int j = Astart; j <= i; j++)
						a.push_back(A[j]);
				}
				if (!m[a])
					m[a] = 1;
				else
					m[a] = 2;
				Astart = i + 1;
			}


		}
		for (int i = 0; i < B.size(); i++)
		{
			string a;

			if (B[i] == ' ' || i == B.size() - 1)
			{
				if (i != B.size() - 1)
				{
					for (int j = Bstart; j < i; j++)
						a.push_back(B[j]);
				}
				else
				{
					for (int j = Bstart; j <= i; j++)
						a.push_back(B[j]);

				}
				if (!m[a])
					m[a] = 1;
				else
					m[a] = 2;
				Bstart = i + 1;
			}


		}
		auto it = m.begin();
		for (it; it != m.end(); it++)
		{
			if (it->second == 1)
				ans.push_back(it->first);
		}





		return ans;

	}
};