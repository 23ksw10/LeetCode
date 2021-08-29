#include <iostream>
#include <vector>
#include <stack>


using namespace std;


 
 
class Solution {
public:
	vector<int> canSeePersonsCount(vector<int>& heights) {
		int n = heights.size();
		vector<int>ans(n, 0);
		stack<int>s;
		s.push(heights[n - 1]);
		for (int i = n - 2; i >= 0; i--) {
			int count = 1;
			while (s.size() && s.top() < heights[i]) {
				count++;
				s.pop();
			}
			if (s.size() == 0)count -= 1;
			s.push(heights[i]);
			ans[i] = count;
		}
		return ans;
	}
};
