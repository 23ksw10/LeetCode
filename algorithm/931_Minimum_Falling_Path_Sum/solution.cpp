#include <iostream>
#include <algorithm>
#include <vector>





using namespace std;




class Solution {
public:
	int minFallingPathSum(vector<vector<int>>& A) {
		int ans = 0;
		int row = A.size();
		int column = A[0].size();
		for (int i = 1; i < row; i++)
			for (int j = 0; j < column; j++)
			{
				A[i][j] += min({ A[i - 1][max(j - 1,0)], A[i - 1][j], A[i - 1][min(j + 1,column - 1)] });
			}
		for (int j = 0; j < column; j++)
		{
			ans = min(A[row - 1][j], ans);
		}
		return ans;

	}
};