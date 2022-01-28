#include <iostream>
#include <vector>




using namespace std;


 

class Solution {
public:
	int minPatches(vector<int>& nums, int n) {
		int ans = 0;
		long long sum = 0;
		int m = nums.size();
		for (int i = 0; i < m; i++) {
			if (sum >= n)break;
			if (nums[i] > sum + 1) {
				ans += 1;
				sum += sum + 1;
				i--;
			}
			else {
				sum += nums[i];
			}
		}
		while (sum < n) {
			sum += sum + 1;
			ans++;
		}
		return ans;
	}
};