#include <iostream>
#include <vector>
#include <deque>



using namespace std;

class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int>ans;
		deque<int>dq;

		for (int i = 0; i < nums.size(); i++) {
			while (dq.size() > 0 && nums[dq.front()] <= nums[i]) {
				dq.pop_front();
			}
			dq.push_front(i);
			if (i - dq.back() >= k) dq.pop_back();
			if (i >= k - 1)ans.push_back(nums[dq.back()]);
		}


		return ans;
	}
};