#include <iostream>
#include <vector>






using namespace std;


class Solution {
public:
	vector<vector<int>> largeGroupPositions(string s) {
		vector<vector<int>>ans;
		int count = 0;
		int sz = s.size();
		for (int i = 0; i < sz; i++) {
			if (!i)count++;
			else {
				if (s[i] != s[i - 1]) {
					if (count > 2)ans.push_back({ i - count,i - 1 });
					count = 1;
				}
				else count++;
			}
		}
		if (count > 2)ans.push_back({ sz - count,sz - 1 });
		return ans;
	}
};