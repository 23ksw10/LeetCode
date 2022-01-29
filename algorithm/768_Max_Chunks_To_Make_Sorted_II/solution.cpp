#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;


class Solution {
public:
	int maxChunksToSorted(vector<int>& arr) {
		int n = arr.size();
		vector<int>leftmax(n + 1);
		vector<int>rightmin(n + 1);
		leftmax[0] = arr[0];
		for (int i = 1; i < n; i++) {
			leftmax[i] = max(leftmax[i - 1], arr[i]);
		}
		rightmin[n] = INT_MAX;
		rightmin[n - 1] = arr[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			rightmin[i] = min(rightmin[i + 1], arr[i]);
		}
		int ans = 0;
		for (int i = 0; i < n; i++) {
			if (leftmax[i] <= rightmin[i + 1])ans++;
		}
		return ans;

	}
};