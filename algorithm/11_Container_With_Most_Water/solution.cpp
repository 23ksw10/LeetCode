#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;


class Solution {
public:
	int maxArea(vector<int>& height) {
		int s = height.size();
		int l = 0;
		int r = s - 1;
		int ans = 0;
		while (l < r) {
			int h = min(height[r], height[l]);
			ans = max(ans, h*(r - l));
			if (height[r] < height[l]) r--;
			else l++;
		}
		return ans;
	}
};