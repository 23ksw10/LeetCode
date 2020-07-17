#include <iostream>
#include <vector>



using namespace std;



class NumMatrix {
public:
	vector<vector<int>> matrix1;
	NumMatrix(vector<vector<int>>& matrix) {
		if (matrix.size() == 0)return;
		matrix1 = vector<vector<int>>(matrix.size() + 1, vector<int>(matrix[0].size() + 1, 0));
		for (int i = 1; i <= matrix.size(); i++) {
			for (int j = 1; j <= matrix[0].size(); j++) {
				matrix1[i][j] = matrix1[i - 1][j] + matrix1[i][j - 1] + matrix[i - 1][j - 1] - matrix1[i - 1][j - 1];

			}


		}



	}

	int sumRegion(int row1, int col1, int row2, int col2) {

		return matrix1[row2 + 1][col2 + 1] - matrix1[row2 + 1][col1] - matrix1[row1][col2 + 1] + matrix1[row1][col1];

	}
};