#include <iostream>
#include <vector>




using namespace std;


class Solution {
public:
	int trap(vector<int>& height) {
		int lmax = 0;
		int rmax = 0;
		int l = 0;
		int r = height.size() - 1;
		int ans = 0;
		while (l < r) {
			if (height[l] < height[r]) {
				if (lmax < height[l])lmax = height[l];
				ans += lmax - height[l];
				l++;
			}
			else {
				if (rmax < height[r])rmax = height[r];
				ans += rmax - height[r];
				r--;
			}
		}
		return ans;
	}
};