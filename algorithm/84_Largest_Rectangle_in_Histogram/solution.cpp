#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>



using namespace std;



class Solution {
public:
	int largestRectangleArea(vector<int>& heights) {
		int ans = 0;
		stack<int>s;
		s.push(-1);
		heights.push_back(0);
		int l = heights.size();
		for (int i = 0; i < l; i++) {
			while (s.top() >= 0 && heights[i] < heights[s.top()]) {
				int h = heights[s.top()];
				s.pop();
				int w = i - s.top() - 1;
				ans = max(ans, h*w);

			}

			s.push(i);

		}

		return ans;
	}
};