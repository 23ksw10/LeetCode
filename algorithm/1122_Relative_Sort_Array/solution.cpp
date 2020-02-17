#include <iostream>
#include <vector>
#include <map>



using namespace std;



class Solution {
public:
	vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
		vector<int> ans;
		map<int, int>m;
		for (int i = 0; i < arr1.size(); i++)
		{
			++m[arr1[i]];
		}
		for (int i = 0; i < arr2.size(); i++)
		{
			while (m[arr2[i]]-- > 0)
			{
				ans.push_back(arr2[i]);
			}

		}
		auto it = m.begin();
		for (it; it != m.end(); it++)
		{
			while (it->second-- > 0)
			{
				ans.push_back(it->first);
			}
		}
		return ans;

	}
};
