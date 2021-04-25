#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;


 
class Solution {
public:
	int leastBricks(vector<vector<int>>& wall) {
		int ans = 0;
		unordered_map<int, int>m;
		for (auto &a : wall) {
			int k = 0;
			for (int i = 0; i < a.size() - 1; i++) {
				k += a[i];
				m[k]++;
			}
		}
		for (auto it = m.begin(); it != m.end(); it++) {
			ans = max(ans, it->second);
		}
		return wall.size() - ans;
	}
};