#include <iostream>
bool isBadVersion(int version);



using namespace std;

class Solution {
public:
	int firstBadVersion(int n) {
		int start = 1;
		int end = n;
		int ans = 0;

		while (start <= end) {
			int m = start + (end - start) / 2;
			if (isBadVersion(m)) {
				end = m - 1;
				ans = m;

			}
			else {
				start = m + 1;

			}
		}
		return ans;

	}
};