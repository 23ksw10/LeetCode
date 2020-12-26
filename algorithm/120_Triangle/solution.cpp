#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;



class Solution {
public:
	int minimumTotal(vector<vector<int>>& triangle) {
		int ans = 1000000000;
		for (int i = 1; i < triangle.size(); i++) {
			for (int j = 0; j < triangle[i].size(); j++) {
				if (!j)triangle[i][j] = triangle[i][j] + triangle[i - 1][j];
				else if (j == triangle[i].size() - 1)triangle[i][j] = triangle[i][j] + triangle[i - 1][j - 1];
				else triangle[i][j] = min(triangle[i][j] + triangle[i - 1][j], triangle[i][j] + triangle[i - 1][j - 1]);
			}
		}

		for (int i = 0; i < triangle[triangle.size() - 1].size(); i++) {
			ans = min(triangle[triangle.size() - 1][i], ans);
		}
		return ans;
	}
};