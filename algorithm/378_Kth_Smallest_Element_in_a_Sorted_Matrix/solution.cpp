#include <iostream>
#include <vector>



using namespace std;



class Solution {
public:
	int kthSmallest(vector<vector<int>>& matrix, int k) {
		int n = matrix.size();
		int l = matrix[0][0];
		int r = matrix[n - 1][n - 1];
		int ans = -100;
		while (l <= r) {
			int m = l + (r - l) / 2;
			int count = 0;
			for (int i = 0; i < n; i++) {
				for (int j = n - 1; j >= 0; j--) {
					if (matrix[i][j] <= m) {
						count += j + 1;
						break;
					}

				}
			}
			if (count >= k) {
				r = m - 1;
				ans = m;
			}
			else l = m + 1;
		}
		return ans;
	}
};