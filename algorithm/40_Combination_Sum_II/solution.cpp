#include <iostream>
#include <algorithm>
#include <vector>





using namespace std;

  



 
 
  class Solution {
  public:
	  vector<vector<int>>ans;
	  void help(vector<int>& candidates, int target, vector<int>tmp, int index, int sum) {
		  if (sum > target)return;
		  if (sum == target) {
			  ans.push_back(tmp);
			  return;
		  }
		  else {


			  for (int i = index; i < candidates.size(); i++) {
				  if (i > index&&candidates[i] == candidates[i - 1])continue;
				  tmp.push_back(candidates[i]);
				  help(candidates, target, tmp, i + 1, sum + candidates[i]);
				  tmp.pop_back();

			  }

		  }
	  }
	  vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
		  vector<int>v;
		  sort(candidates.begin(), candidates.end());
		  help(candidates, target, v, 0, 0);

		  return ans;


	  }
  };