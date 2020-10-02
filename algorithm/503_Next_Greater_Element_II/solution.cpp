#include <iostream>
#include <stack>
#include <vector>


using namespace std;

class Solution {
public:
	vector<int> nextGreaterElements(vector<int>& nums) {
		vector<int>ans(nums.size(), 0);
		stack<int>r;

		for (int i = nums.size() - 1; i >= 0; i--) {
			while (!r.empty() && r.top() <= nums[i]) {
				r.pop();
			}

			if (r.empty())ans[i] = -1;
			else ans[i] = r.top();

			r.push(nums[i]);
		}
		for (int i = nums.size() - 1; i >= 0; i--) {
			while (!r.empty() && r.top() <= nums[i]) {
				r.pop();
			}

			if (r.empty()) {
				ans[i] = -1;
				break;
			}
			else ans[i] = r.top();
			r.push(nums[i]);


		}


		return ans;
	}
};