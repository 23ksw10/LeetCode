#include <iostream>
#include <vector>
#include <algorithm>


using namespace std;



class Solution {
public:
	int longestMountain(vector<int>& arr) {
		if (arr.size() < 3)return 0;
		int ans = 0;
		int i = 1;
		while (i < arr.size()) {
			while (i < arr.size() && arr[i] == arr[i - 1]) {
				i++;
			}
			int down = 0;
			while (i<arr.size() && arr[i]>arr[i - 1]) {
				down++;
				i++;
			}
			int up = 0;
			while (i < arr.size() && arr[i] < arr[i - 1]) {
				up++;
				i++;
			}
			if (down&&up)ans = max(ans, up + down + 1);
		}
		return ans;
	}
};