#include <iostream>
#include <vector>





using namespace std;



class Solution {
public:
	int ud[4] = { -1,0,1,0 };
	int lr[4] = { 0,1,0,-1 };
	bool help(vector<vector<char>>& board, string word, int i, int j, int index) {
		if (index == word.size()) {
			return true;
		}
		for (int k = 0; k < 4; k++) {
			int a = i + ud[k];
			int b = j + lr[k];
			if (a >= 0 && a < board.size() && b >= 0 && b < board[0].size()) {
				if (board[a][b] == word[index]) {
					board[a][b] = '1';
					if (help(board, word, a, b, index + 1))return true;
					board[a][b] = word[index];
				}
			}

		}
		return false;
	}
	bool exist(vector<vector<char>>& board, string word) {
		if (word == "")return false;
		for (int i = 0; i < board.size(); i++) {
			for (int j = 0; j < board[i].size(); j++) {
				if (board[i][j] == word[0]) {
					board[i][j] = '1';
					if (help(board, word, i, j, 1))return true;
					board[i][j] = word[0];
				}
			}
		}
		return false;
	}
};