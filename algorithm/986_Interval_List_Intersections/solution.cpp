#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;



class Solution {
public:
	vector<vector<int>> intervalIntersection(vector<vector<int>>& A, vector<vector<int>>& B) {
		vector<vector<int>> ans;
		for (int i = 0, j = 0; i < A.size() && j < B.size();)
		{
			vector<int> a;

			int high = min(A[i][1], B[j][1]);
			int low = max(A[i][0], B[j][0]);

			if (high >= low)
			{
				a.push_back(low);
				a.push_back(high);

				ans.push_back(a);

			}
			if (A[i][1] > B[j][1])
				j++;
			else i++;
		}
		return ans;

	}
};
