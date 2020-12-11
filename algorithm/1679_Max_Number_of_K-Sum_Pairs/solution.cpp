#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;






class Solution {
public:
	int maxOperations(vector<int>& nums, int k) {
		int ans = 0;
		unordered_map<int, int>m;
		for (int i = 0; i < nums.size(); i++) {
			if (m.find(k - nums[i]) == m.end())m[nums[i]]++;
			else if (m[k - nums[i]] == 0) {
				m[nums[i]]++;
			}
			else {
				m[k - nums[i]]--;
				ans++;
			}
		}
		return ans;
	}
};