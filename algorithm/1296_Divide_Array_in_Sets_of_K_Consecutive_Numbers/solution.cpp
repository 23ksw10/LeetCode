#include <iostream>
#include <vector>
#include <map>





using namespace std;


class Solution {
public:
	bool isPossibleDivide(vector<int>& nums, int k) {
		map<int, int>check;
		for (int i = 0; i < nums.size(); i++) {
			check[nums[i]]++;
		}
		for (auto it = check.begin(); it != check.end(); it++) {
			if (it->second < 1)continue;
			while (it->second) {
				for (int i = 1; i < k; i++) {
					if (check[it->first + i])check[it->first + i]--;
					else return false;
				}
				check[it->first]--;

			}
		}
		return true;
	}
};