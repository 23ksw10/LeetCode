#include <iostream>
#include<vector>


using namespace std;

class Solution {
public:
	vector<int> diStringMatch(string S) {
		vector<int>ans;
		int u = 0;
		int d = S.size();
		for (auto i : S)
		{

			if (i == 'I')
				ans.push_back(u++);
			else
				ans.push_back(d--);


		}
		ans.push_back(u);
		return ans;

	}
};;
