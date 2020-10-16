#include <iostream>
#include <vector>
#include <queue>



using namespace std;

class Solution {
public:
	int minFlips(vector<vector<int>>& mat) {
		int n = mat.size();
		int m = mat[0].size();
		int total = n * m;
		int state = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (mat[i][j])state |= 1 << (i*m + j);
			}
		}
		int d_x[4] = { 0,1,0,-1 };
		int d_y[4] = { -1,0,1,0 };
		vector<bool>check(1 << total, false);
		queue<int>q;
		q.push(state);
		check[state] = true;
		int step = 0;
		while (!q.empty()) {
			int size = q.size();
			for (int k = 0; k < size; k++) {
				auto a = q.front();
				q.pop();
				if (a == 0)return step;
				for (int l = 0; l < total; l++) {
					int tmp = a;
					tmp ^= (1 << l);
					int i = l / m;
					int j = l % m;
					for (int d = 0; d < 4; d++) {
						int new_i = i + d_y[d];
						int new_j = j + d_x[d];
						if (new_i >= 0 && new_i < n&&new_j >= 0 && new_j < m) {
							tmp ^= (1 << (new_i*m + new_j));

						}
					}
					if (!check[tmp]) {
						q.push(tmp);
						check[tmp] = true;
					}
				}

			}
			step++;
		}
		return -1;
	}
};