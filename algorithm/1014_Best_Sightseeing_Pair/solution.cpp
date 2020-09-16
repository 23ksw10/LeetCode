#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	int maxScoreSightseeingPair(vector<int>& A) {
		int ans = 0;
		int b = 0;
		for (int i = 0; i < A.size(); i++) {
			ans = max(ans, b + A[i] - i);
			b = max(b, A[i] + i);

		}
		return ans;
	}
};