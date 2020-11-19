#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:
	void rotate(vector<vector<int>>& matrix) {
		int n = matrix.size();
		int m;
		if (n % 2)m = n / 2;
		else m = n / 2 - 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				swap(matrix[i][j], matrix[i][n - j - 1]);
			}
		}
		m = n;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				swap(matrix[i][j], matrix[n - j - 1][n - i - 1]);
			}
			m--;
		}

	}
};