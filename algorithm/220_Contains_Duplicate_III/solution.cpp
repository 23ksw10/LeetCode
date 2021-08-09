#include <iostream>
#include <unordered_map>
#include <vector>




using namespace std;


 
 
class Solution {
public:
	bool containsNearbyAlmostDuplicate(vector<int>& nums, int k, int t) {
		unordered_map<long long, long long>m;
		int n = nums.size();
		if (n == 0 || k < 0 || t < 0) return false;
		for (int i = 0; i < n; i++) {
			long long tmp = nums[i] / ((long long)t + 1);
			if (nums[i] < 0)tmp--;
			if (m.find(tmp) != m.end())return true;
			if (m.find(tmp + 1) != m.end() && (long long)m[tmp + 1] - (long long)nums[i] <= t)return true;
			if (m.find(tmp - 1) != m.end() && (long long)-m[tmp - 1] + (long long)nums[i] <= t)return true;
			m[tmp] = nums[i];
			if (m.size() > k) {
				long long ktmp = nums[i - k] / ((long long)t + 1);
				if (nums[i - k] < 0)ktmp--;
				m.erase(ktmp);
			}
		}
		return false;
	}
};