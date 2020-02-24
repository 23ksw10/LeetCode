#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;



class Solution {
public:
	int removeCoveredIntervals(vector<vector<int>>& intervals) {

		sort(intervals.begin(), intervals.end(), [](const auto &a, const auto &b) {return abs(a[0] - a[1]) >=
			abs(b[0] - b[1])
			|| abs(a[0] - a[1]) ==
			abs(b[0] - b[1]) && a[1] > b[1];
		});
		for (int i = 0; i < intervals.size(); i++)
		{
			for (int j = i + 1; j < intervals.size(); )
			{
				if (intervals[i][0] <= intervals[j][0] && intervals[i][1] >= intervals[j][1])
				{

					intervals.erase(intervals.begin() + j);
				}
				else j++;
			}
		}
		return intervals.size();


	}
};