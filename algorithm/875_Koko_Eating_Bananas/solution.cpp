#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;


 

class Solution {
public:
	int minEatingSpeed(vector<int>& piles, int h) {
		int k = 0;
		int l = 1;
		auto it = max_element(piles.begin(), piles.end());
		int r = *it;
		while (l < r) {
			int m = l + (r - l) / 2;
			int tmp = 0;
			for (int i = 0; i < piles.size(); i++) {
				tmp += (piles[i] - 1) / m + 1;
			}
			if (tmp > h) {
				l = m + 1;
			}
			else {
				r = m;
			}
		}
		return l;
	}
};