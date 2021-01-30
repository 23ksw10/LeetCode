#include <iostream>
#include <algorithm>
#include <vector>



using namespace std;




class Solution {
public:
	double trimMean(vector<int>& arr) {
		sort(arr.begin(), arr.end());
		int s = arr.size();
		double ans = 0;

		for (int i = s / 20; i < s - (s / 20); i++) {

			ans += arr[i];
		}
		return ans / (s / 10 * 9);

	}
};