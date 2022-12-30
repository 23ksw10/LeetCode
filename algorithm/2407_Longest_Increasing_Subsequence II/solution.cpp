#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


struct seg {
	vector<long long>t;
	seg(int x) :t(4 * x) {}
	void setValue(int value, int index, int l = 0, int r = 100000, int v = 1) {
		if (l == r) {
			t[v] = value;

		}
		else {
			int h = l + r >> 1;
			if (index <= h)setValue(value, index, l, h, 2 * v);
			else setValue(value, index, h + 1, r, 2 * v + 1);
			t[v] = max(t[2 * v], t[2 * v + 1]);
		}
	}
	long long getMax(int l, int r, int L = 0, int R = 100000, int v = 1) {
		if (l <= L && R <= r)return t[v];
		else if (l > R)return INT_MIN;
		else if (r < L)return INT_MIN;
		int h = L + R >> 1;
		return max(getMax(l, r, L, h, 2 * v), getMax(l, r, h + 1, R, 2 * v + 1));

	}

};

class Solution {
public:
	int lengthOfLIS(vector<int>& nums, int k) {
		int n = nums.size();
		int mx = 0;
		int ans = 0;
		seg s(100000);
		for (auto n : nums) {
			mx = max(mx, n);
		}
		for (int i = 0; i <= mx; i++) {
			s.setValue(0, i);
		}
		for (int i = 1; i <= n; i++) {
			int d = nums[i - 1];
			int l = max(0, d - k);
			int r = d - 1;
			int m = s.getMax(l, r) + 1;
			s.setValue(m, d);
		}
		return s.t[1];
	}
};

