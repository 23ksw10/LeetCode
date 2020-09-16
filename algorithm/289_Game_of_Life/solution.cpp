#include <iostream>
#include <vector>

using namespace std;


class Solution {
public:

	void gameOfLife(vector<vector<int>>& board) {
		int n = board.size();
		int m = board[0].size();
		int a[8] = { -1,-1,-1,0,0,1,1,1 };
		int b[8] = { -1,0,1,-1,1,-1,0,1 };
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j]) {
					int live = 0;
					for (int k = 0; k < 8; k++) {
						int n_i = i + a[k];
						int n_j = j + b[k];
						if (n_i >= 0 && n_i < n&&n_j >= 0 && n_j < m) {
							if (board[n_i][n_j] > 0)live++;
						}

					}
					if (live < 2)board[i][j] = 2;
					else if (live <= 3)board[i][j] = 1;
					else board[i][j] = 2;
				}
				if (!board[i][j]) {
					int live = 0;
					for (int k = 0; k < 8; k++) {
						int n_i = i + a[k];
						int n_j = j + b[k];
						if (n_i >= 0 && n_i < n&&n_j >= 0 && n_j < m) {
							if (board[n_i][n_j] > 0)live++;
						}


					}
					if (live == 3)board[i][j] = -1;
				}
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (board[i][j] == 2)board[i][j] = 0;
				if (board[i][j] == -1)board[i][j] = 1;
			}
		}
	}
};