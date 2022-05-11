#include <iostream>
#include <vector>
#include <queue>



using namespace std;


class Solution {
public:
	int minimumOperations(vector<int>& nums, int start, int goal) {
		vector<int>visit(1001, 0);
		queue<int>q;
		q.push(start);
		int ans = 0;
		while (q.size()) {
			int s = q.size();
			for (int i = 0; i < s; i++) {
				auto a = q.front();
				q.pop();
				if (a == goal)return ans;
				if (a > 1000 || a < 0 || visit[a])continue;
				visit[a] = 1;
				for (auto &n : nums) {

					q.push(a + n);


					q.push(a - n);


					q.push(a^n);

				}
			}
			ans++;
		}
		return -1;
	}
};