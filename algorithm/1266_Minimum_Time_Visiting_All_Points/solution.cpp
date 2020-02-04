#include <iostream>
#include <string>
#include<vector>

using namespace std;



class Solution {
public:
	int minTimeToVisitAllPoints(vector<vector<int>>& points) {
		int x;
		int y;
		int ans = 0;
		for (int i = 0; i < points.size() - 1; i++)
		{

			x = abs(points[i + 1].at(0) - points[i].at(0));
			y = abs(points[i + 1].at(1) - points[i].at(1));

			if (x >= y)
				ans += x;
			else
				ans += y;

		}
		return ans;
	}
};

