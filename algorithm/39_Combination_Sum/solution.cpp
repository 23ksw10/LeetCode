#include <iostream>
#include <algorithm>
#include <vector>


using namespace std;


class Solution {
public:
	vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
		vector<vector<int>> ans;
		vector<int> combination;
		sort(candidates.begin(), candidates.end());
		calculate(ans, candidates, target, 0, combination);


		return ans;

	}
	void calculate(vector<vector<int>> &ans, vector<int>& candidates, int target, int i, vector<int> &combination) {


		if (!target)
		{


			ans.push_back(combination);

			return;
		}

		for (; i < candidates.size() && target >= candidates[i]; i++)
		{
			combination.push_back(candidates[i]);
			calculate(ans, candidates, target - candidates[i], i, combination);
			combination.pop_back();


		}


	}


};