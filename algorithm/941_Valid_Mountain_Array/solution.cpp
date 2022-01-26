#include <iostream>
#include <vector>



using namespace std;


 
 
class Solution {
public:
	bool validMountainArray(vector<int>& arr) {
		int n = arr.size();
		if (n < 3)return false;
		bool up = true;
		for (int i = 1; i < n; i++) {
			if (up&&arr[i] > arr[i - 1])continue;
			else if (up&&arr[i] == arr[i - 1])return false;
			else if (up&&arr[i] < arr[i - 1]) {
				if (i == 1)return false;
				up = false;
			}
			if (!up&&arr[i] >= arr[i - 1])return false;
		}
		return up == 0 ? true : false;
	}
};