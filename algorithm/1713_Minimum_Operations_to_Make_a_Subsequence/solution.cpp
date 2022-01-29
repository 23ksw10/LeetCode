#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>




using namespace std;


class Solution {
public:
	int minOperations(vector<int>& target, vector<int>& arr) {
		int n = target.size();
		int m = arr.size();
		unordered_map<int, int>mp;
		for (int i = 0; i < n; i++) {
			mp[target[i]] = i;
		}
		vector<int>v;
		vector<int>ans;
		for (int i = 0; i < m; i++) {
			if (mp.find(arr[i]) == mp.end())continue;
			int x = mp[arr[i]];
			if (ans.size() == 0) {
				ans.push_back(x);
			}
			else {
				if (ans.back() < x)ans.push_back(x);
				else {
					auto it = lower_bound(ans.begin(), ans.end(), x);
					ans[it - ans.begin()] = x;
				}
			}
		}


		return n - ans.size();
	}
};