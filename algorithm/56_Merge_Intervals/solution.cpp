#include <iostream>
#include <algorithm>
#include <vector>





using namespace std;

  



 
 
class Solution {
public:
	vector<vector<int>> merge(vector<vector<int>>& intervals) {
		
		if (intervals.size() <= 1)return intervals;
		sort(intervals.begin(), intervals.end());
		int r = intervals[0][1];
		int l = intervals[0][0];
		vector<vector<int>>ans;
		for (int i = 1; i < intervals.size(); i++) {
			if (i == intervals.size() - 1) {
				if (intervals[i][0] <= r) {
					r = max(r, intervals[i][1]);
					ans.push_back({ l,r });
				}
				else {
					ans.push_back({ l,r });
					ans.push_back(intervals[i]);
				}
				break;
			}
			if (intervals[i][0] <= r) {
				r = max(r, intervals[i][1]);
			}
			else {
				ans.push_back({ l,r });
				l = intervals[i][0];
				r = intervals[i][1];
			}
		}
		return ans;
	}
};