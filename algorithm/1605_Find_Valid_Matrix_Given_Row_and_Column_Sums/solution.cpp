#include <iostream>
#include <vector>



using namespace std;



class Solution {
public:
	vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
		int n = rowSum.size();
		int m = colSum.size();
		int req;
		vector<vector<int>>ans(n, vector<int>(m, 0));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				req = min(rowSum[i], colSum[j]);
				ans[i][j] = req;
				rowSum[i] -= req;
				colSum[j] -= req;
			}
		}
		return ans;
	}
};