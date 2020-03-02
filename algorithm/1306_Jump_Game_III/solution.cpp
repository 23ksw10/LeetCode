#include <iostream>
#include <unordered_set>
#include <vector>





using namespace std;




class Solution {
public:
	unordered_set<int> vis;
	bool canReach(vector<int>& arr, int start) {
		if (start >= 0 && start < arr.size() && vis.insert(start).second) {
			return arr[start] == 0 || canReach(arr, start + arr[start]) || canReach(arr, start - arr[start]);
		}
		return false;

	}



};