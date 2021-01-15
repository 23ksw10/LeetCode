#include <iostream>
#include <vector>
#include <algorithm>






using namespace std;




class Solution {
public:
	int numRescueBoats(vector<int>& people, int limit) {
		int ans = 0;
		sort(people.begin(), people.end());
		int l = 0;
		int r = people.size() - 1;
		while (l <= r) {
			int tmp = people[l] + people[r];
			if (tmp <= limit) {
				l++;
				r--;
			}
			else {
				r--;
			}
			ans++;
		}
		return ans;
	}
};