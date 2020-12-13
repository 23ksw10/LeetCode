#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;






class Solution {
public:
	int minimumEffort(vector<vector<int>>& tasks) {
		auto comp = [](vector<int>& a, vector<int>& b) {
			int diff_a = a[1] - a[0];
			int diff_b = b[1] - b[0];

			return diff_a > diff_b;
		};

		sort(tasks.begin(), tasks.end(), comp);

		int energy = tasks[0][1];
		int max_energy = energy;

		for (int i = 1; i < tasks.size(); i++) {
			energy -= tasks[i - 1][1];
			energy += tasks[i - 1][0] + tasks[i][1];
			max_energy = max(max_energy, energy);
		}

		return max_energy;
	}
};