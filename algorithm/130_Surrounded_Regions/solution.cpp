#include <iostream>
#include <vector>
#include <queue>


using namespace std;




class Solution {
public:
	int ud[4] = { -1,0,1,0 };
	int lr[4] = { 0,1,0,-1 };
	void solve(vector<vector<char>>& board) {
		if (board.size() == 0)return;
		int m = board.size();
		int n = board[0].size();
		bool check[m][n];
		memset(check, false, sizeof(check));

		for (int i = 0; i < m; i++) {
			if (i == 0 || i == m - 1) {
				for (int j = 0; j < n; j++) {
					if (board[i][j] == 'O'&&check[i][j] == false)bfs(board, check, i, j);
				}
			}
			else {
				if (board[i][0] == 'O'&&check[i][0] == false)bfs(board, check, i, 0);
				if (board[i][n - 1] == 'O'&&check[i][n - 1] == false)bfs(board, check, i, n - 1);
			}
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == '1')board[i][j] = 'O';
				else board[i][j] = 'X';
			}
		}
	}
	void bfs(vector<vector<char>>& board, bool check[], int i, int j) {
		int m = board.size();
		int n = board[0].size();
		queue<pair<int, int>>q;

		q.push({ i,j });
		bool b = true;
		while (!q.empty()) {
			int s = q.size();
			for (int i = 0; i < s; i++) {
				auto a = q.front();
				q.pop();
				int x = a.first;
				int y = a.second;
				check[x][y] = true;
				board[x][y] = '1';
				for (int i = 0; i < 4; i++) {
					if (x + ud[i] >= 0 && x + ud[i] < m&&y + lr[i] >= 0 && y + lr[i] < n&&board[x + ud[i]][y + lr[i]] == 'O') {
						if (check[x + ud[i]][y + lr[i]] == false) {
							q.push({ x + ud[i],y + lr[i] });

						}
					}
				}
			}
		}

	}
};