#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
	int getXORSum(vector<int>& arr1, vector<int>& arr2) {
		long long all_xor = 0;
		for (auto &a : arr2) {
			all_xor ^= a;
		}
		long long ans = 0;
		for (auto &b : arr1) {
			ans ^= b;
		}
		return ans & all_xor;
	}
};