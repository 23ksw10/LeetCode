#include <iostream>
#include <vector>





using namespace std;



class Solution {
public:
	vector<int> findBall(vector<vector<int>>& grid) {
		int n = grid.size();
		int ball = grid[0].size();
		vector<int>ans(ball, 0);
		for (int i = 0; i < ans.size(); i++) {
			int location = i;
			bool check = true;
			for (int j = 0; j < n; j++) {

				if (location == 0 && grid[j][0] == -1) {
					ans[i] = -1;
					check = false;
					break;
				}
				if (location == ball - 1 && grid[j][location] == 1) {
					ans[i] = -1;
					check = false;
					break;
				}
				if (grid[j][location] == 1 && grid[j][location + 1] == -1) {
					ans[i] = -1;
					check = false;
					break;
				}
				if (grid[j][location] == -1 && grid[j][location - 1] == 1) {
					ans[i] = -1;
					check = false;
					break;
				}
				if (grid[j][location] == 1)location++;
				else location--;

			}
			if (check)ans[i] = location;

		}
		return ans;
	}
};