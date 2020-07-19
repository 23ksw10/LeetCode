#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



class Solution {
public:
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int K) {
		int n = mat[0].size();
		int m = mat.size();
		vector<vector<int>>ans(m, vector<int>(n, 0));
		for (int i = 0; i < mat.size(); i++) {
			for (int j = 1; j < mat[0].size(); j++) {
				mat[i][j] += mat[i][j - 1];
			}
		}
		for (int i = 1; i < mat.size(); i++) {
			for (int j = 0; j < mat[0].size(); j++) {
				mat[i][j] += mat[i - 1][j];
			}
		}
		for (int i = 0; i < ans.size(); i++) {
			for (int j = 0; j < ans[0].size(); j++) {
				ans[i][j] = mat[min(i + K, m - 1)][min(j + K, n - 1)];
				if (i - K - 1 >= 0)ans[i][j] -= mat[i - K - 1][min(j + K, n - 1)];
				if (j - K - 1 >= 0)ans[i][j] -= mat[min(i + K, m - 1)][j - K - 1];
				if (j - K - 1 >= 0 && i - K - 1 >= 0) ans[i][j] += mat[i - K - 1][j - K - 1];
			}
		}

		return ans;
	}
};