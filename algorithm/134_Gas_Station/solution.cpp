#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;

  
class Solution {
public:
	int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
		int total_cost = 0;
		int reduce = 0;
		int ans;
		for (int i = 0; i < gas.size(); i++) {
			total_cost += gas[i] - cost[i];
			if (total_cost < 0) {
				reduce += total_cost;
				ans = i + 1;
				total_cost = 0;
			}
		}
		if (total_cost + reduce >= 0)return ans;
		return -1;
	}
};