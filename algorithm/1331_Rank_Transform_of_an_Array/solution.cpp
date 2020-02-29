#include <iostream>
#include <algorithm>
#include <vector>



using namespace std;




class Solution {
public:
	vector<int> arrayRankTransform(vector<int>& arr) {
		vector<int> c(arr);
		vector<int> ans;

		sort(c.begin(), c.end());
		unordered_map<int, int>m;
		int rank = 1;
		for (int i = 0; i < c.size(); i++)
		{
			if (i == 0 || c[i] != c[i - 1])
			{
				m[c[i]] = rank++;
			}
		}
		for (int i = 0; i < arr.size(); i++)
		{
			ans.push_back(m[arr[i]]);
		}


		return ans;



	}
};
