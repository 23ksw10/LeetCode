#include <iostream>
#include <vector>



using namespace std;



class Solution {
public:
	int findJudge(int N, vector<vector<int>>& trust) {
		vector<int>check(N + 1, 0);
		for (auto &a : trust) {
			check[a[1]]++;
			check[a[0]]--;
		}
		int ans = -1;
		for (int i = 0; i < N + 1; i++) {
			if (check[i] == N - 1)ans = i;
		}
		return ans;
	}
};