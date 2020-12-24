#include <iostream>
#include <vector>



using namespace std;



class Solution {
public:
	int help(vector<vector<int>>& mat, int a, int b) {
		int m = mat.size();
		int n = mat[0].size();
		int count = 0;
		for (int i = a; i < m; i++) {
			for (int j = b; j < n; j++) {
				if (mat[i][j])count++;
				else n = j;
			}
		}
		return count;
	}
	int numSubmat(vector<vector<int>>& mat) {
		int m = mat.size();
		int n = mat[0].size();
		int ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				ans += help(mat, i, j);
			}
		}
		return ans;

	}
};