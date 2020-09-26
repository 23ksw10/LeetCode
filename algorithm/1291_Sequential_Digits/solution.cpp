#include <iostream>
#include <vector>
#include <string>




using namespace std;

  


class Solution {
public:
	vector<int> sequentialDigits(int low, int high) {
		vector<int>ans;
		string number = "123456789";
		int tmp_low = low;
		int tmp_high = high;
		int low_count = 0;
		int high_count = 0;
		while (tmp_low) {
			tmp_low = tmp_low / 10;
			low_count++;
		}
		while (tmp_high) {
			tmp_high = tmp_high / 10;
			high_count++;
		}
		bool complete = false;
		int range = low_count;
		while (!complete) {
			for (int i = 0; i < number.size(); i++) {
				if (i + range > number.size()) {
					range++;
					break;
				}
				string t = number.substr(i, low_count);
				int tmp = stoi(t);
				if (tmp >= low && tmp <= high)ans.push_back(tmp);
				else {
					complete = true;
					break;
				}

			}
		}
		return ans;

	}
};