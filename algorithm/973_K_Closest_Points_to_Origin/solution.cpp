#include <iostream>
#include <vector>
#include <map>


using namespace std;



class Solution {
public:
	vector<vector<int>> kClosest(vector<vector<int>>& points, int K) {

		multimap<int, int>m;
		vector<vector<int>> ans;
		for (int i = 0; i < points.size(); i++)
		{
			int x = points[i][0];
			int y = points[i][1];
			int distance = x * x + y * y;

			m.insert({ distance, i });
		}
		auto it = m.begin();
		for (it, K; K > 0; it++, K--)
		{
			ans.push_back(points[it->second]);
		}

		return ans;

	}
};