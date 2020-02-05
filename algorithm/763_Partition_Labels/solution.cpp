#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;



class Solution {
public:
	vector<int> partitionLabels(string S) {
		vector <int> last(26, 0);
		for (int i = 0; i < S.size(); i++)
		{
			last[S[i] - 'a'] = i;
		}
		vector<int> ans;
		int j = 0;
		int k = 0;
		for (int i = 0; i < S.size(); i++)
		{
			j = max(j, last[S[i] - 'a']);
			if (j == i)
			{
				ans.push_back(i + 1 - k);
				k = j + 1;
			}
		}

		return ans;
	}
};