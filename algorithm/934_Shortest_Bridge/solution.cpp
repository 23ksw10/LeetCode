#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;

  
class Solution {
public:
	int lr[4] = { 0,1,0,-1 };
	int ud[4] = { -1,0,1,0 };
	queue<vector<int>>q;
	int shortestBridge(vector<vector<int>>& A) {
		int n = A.size();
		int m = A[0].size();
		int ans = 100000000;

		bool check = true;
		for (int i = 0; i < n; i++) {

			for (int j = 0; j < m; j++) {
				if (A[i][j]) {
					dfs(i, j, A);
					check = false;
					break;
				}
			}
			if (!check)break;
		}


		while (!q.empty()) {
			auto tmp = q.front();
			q.pop();
			int i = tmp[0];
			int j = tmp[1];
			for (int k = 0; k < 4; k++) {
				int next_i = i + ud[k];
				int next_j = j + lr[k];

				if (next_i >= 0 && next_i < n&&next_j >= 0 && next_j < m) {
					if (A[next_i][next_j] == 1) {
						ans = min(A[i][j] - 2, ans);
						break;
					}
					if (A[next_i][next_j] == 0) {

						A[next_i][next_j] = A[i][j] + 1;

						q.push({ next_i,next_j });
					}
				}
			}
		}
		for (int i = 0; i < n; i++) {

			for (int j = 0; j < m; j++) {
				cout << A[i][j];
			}
			cout << endl;
		}


		return ans;
	}
	void dfs(int i, int j, vector<vector<int>>&A) {
		A[i][j] = 2;
		int n = A.size();
		int m = A[0].size();
		q.push({ i,j });
		for (int k = 0; k < 4; k++) {
			int next_i = i + ud[k];
			int next_j = j + lr[k];
			if (next_i >= 0 && next_i < n&&next_j >= 0 && next_j < m&&A[next_i][next_j] == 1) {
				dfs(next_i, next_j, A);
			}
		}
	}

};