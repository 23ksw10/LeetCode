#include <iostream>
#include <vector>
#include <string>
#include <algorithm>



using namespace std;

  


class Solution {
public:
	bool checkValidString(string s) {
		int max_count = 0;
		int min_count = 0;
		for (auto c : s) {
			if (c == '(') {
				max_count++;
				min_count++;
			}
			else if (c == ')') {
				max_count--;
				min_count = max(min_count - 1, 0);
			}
			else {
				max_count++;
				min_count = max(min_count - 1, 0);
			}
			if (max_count < 0)return false;
		}

		return min_count == 0;

	}
};