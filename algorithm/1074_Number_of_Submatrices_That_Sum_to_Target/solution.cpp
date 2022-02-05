#include <iostream>
#include <vector>
#include <unordered_map>




using namespace std;


class Solution {
public:
	int numSubmatrixSumTarget(vector<vector<int>>& matrix, int target) {
		int n = matrix.size();
		int m = matrix[0].size();
		for (auto &a : matrix) {
			for (int i = 1; i < m; i++) {
				a[i] = a[i - 1] + a[i];
			}
		}
		int ans = 0;
		for (int i = 0; i < m; i++) {
			for (int j = i; j < m; j++) {
				unordered_map<int, int>mp;
				mp[0] = 1;
				int sum = 0;
				for (int k = 0; k < n; k++) {
					if (i)sum += matrix[k][j] - matrix[k][i - 1];
					else sum += matrix[k][j];
					ans += mp[sum - target];
					mp[sum]++;
				}
			}
		}
		return ans;
	}
};