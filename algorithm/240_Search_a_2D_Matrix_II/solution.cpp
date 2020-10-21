#include <iostream>
#include <vector>





using namespace std;


class Solution {
public:
	bool searchMatrix(vector<vector<int>>& matrix, int target) {
		if (!matrix.size())return false;
		int n = matrix.size();
		int m = matrix[0].size();
		int r = 0;
		int c = matrix[0].size() - 1;
		while (r >= 0 && c < m&&c >= 0 && r < n) {

			if (matrix[r][c] == target)return true;
			else if (matrix[r][c] < target)r++;
			else c--;

		}
		return false;

	}
};