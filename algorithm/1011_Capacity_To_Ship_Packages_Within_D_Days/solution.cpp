#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



class Solution {
public:
	int shipWithinDays(vector<int> weights, int D) {
		int right = 0;
		int left = 0;
		for (int i = 0; i < weights.size(); i++) {
			right += weights[i];
			left = max(left, weights[i]);
		}


		while (left <= right) {
			int mid = (left + right) / 2;
			int day = 1;
			int wei = 0;
			for (int i = 0; i < weights.size() && day <= D; wei += weights[i++]) {

				if (wei + weights[i] > mid) {
					day++;
					wei = 0;

				}
			}
			if (day > D)left = mid + 1;
			else right = mid;
		}
		return left;
	}
};