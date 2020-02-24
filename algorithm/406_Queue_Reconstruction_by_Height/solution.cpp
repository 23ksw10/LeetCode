#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



class Solution {
public:
	vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {


		sort(people.begin(), people.end(), [](const auto&a, const auto&b) {return a[0] > b[0] || a[0] == b[0] && a[1] < b[1]; });
		vector<vector<int>> ans;
		for (auto &p : people)
		{
			ans.insert(ans.begin() + p[1], p);

		}
		return ans;

	}

};