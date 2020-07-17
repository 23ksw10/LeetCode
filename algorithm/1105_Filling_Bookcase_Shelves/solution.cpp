#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;



class Solution {
public:
	int minHeightShelves(vector<vector<int>>& books, int shelf_width) {
		vector<int>dp(books.size() + 1, 0);
		for (int i = 0; i < books.size(); i++) {
			dp[i + 1] = dp[i] + books[i][1];
			int width = 0;
			int height = 0;
			for (int j = i; j >= 0; j--) {
				width += books[j][0];
				height = max(height, books[j][1]);
				if (width > shelf_width)break;
				dp[i + 1] = min(dp[i + 1], dp[j] + height);
			}
		}
		return dp[books.size()];

	}
};