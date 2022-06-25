#include <iostream>
#include <vector>


using namespace std;


class Solution {
public:
	vector<int> spiralOrder(vector<vector<int>>& matrix) {
		vector<int>ans;
		int l = 0;
		int r = matrix[0].size() - 1;
		int t = 0;
		int b = matrix.size() - 1;
		int count = matrix[0].size()*matrix.size();
		while (count) {
			for (int i = l; i <= r && count > 0; i++) {
				ans.push_back(matrix[t][i]);
				count--;
			}
			t++;
			for (int i = t; i <= b && count > 0; i++) {
				ans.push_back(matrix[i][r]);
				count--;
			}
			r--;
			for (int i = r; i >= l && count > 0; i--) {
				ans.push_back(matrix[b][i]);
				count--;
			}
			b--;
			for (int i = b; i >= t && count > 0; i--) {
				ans.push_back(matrix[i][l]);
				count--;
			}
			l++;
		}
		return ans;
	}
};