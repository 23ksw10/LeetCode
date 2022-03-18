#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

class Solution {
public:
    int dp[4][501][501];
    int lr[4] = { 0,1,0,-1 };
    int ud[4] = { -1,0,1,0 };
    int dfs(int r, int c, int n, vector<vector<int>>& v, int dir) {
        if (r < 0 || r == n || c < 0 || c == n)return 0;
        if (!v[r][c])return 0;
        if (dp[dir][r][c])return dp[dir][r][c];
        if (dir == 0) {
            dp[dir][r][c] = dfs(r - 1, c, n, v, dir) + 1;
        }
        else if (dir == 1) {
            dp[dir][r][c] = dfs(r, c + 1, n, v, dir) + 1;
        }
        else if (dir == 2) {
            dp[dir][r][c] = dfs(r + 1, c, n, v, dir) + 1;
        }
        else {
            dp[dir][r][c] = dfs(r, c - 1, n, v, dir) + 1;
        }
        return dp[dir][r][c];
    }
    int orderOfLargestPlusSign(int n, vector<vector<int>>& mines) {
        vector<vector<int>>v(n, vector<int>(n, 1));
        for (auto& m : mines) {
            v[m[0]][m[1]] = 0;
        }
        int ans = INT_MIN;
        int tmp = INT_MAX;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                for (int k = 0; k < 4; k++) {
                    dp[k][i][j] = dfs(i, j, n, v, k);
                    tmp = min(tmp, dp[k][i][j]);
                }
                ans = max(ans, tmp);
                // cout<<tmp<<endl;
                tmp = n;
            }
        }
        return ans;
    }
};