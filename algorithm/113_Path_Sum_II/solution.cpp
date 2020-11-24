#include <iostream>
#include <vector>


using namespace std;






  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
      TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
  class Solution {
  public:
	  vector<vector<int>>ans;
	  vector<vector<int>> pathSum(TreeNode* root, int sum) {
		  help(root, sum, {});
		  return ans;
	  }
	  void help(TreeNode* root, int sum, vector<int>tmp) {
		  if (!root) return;
		  tmp.push_back(root->val);
		  if (!root->left && !root->right&&sum - root->val == 0)ans.push_back(tmp);
		  help(root->left, sum - root->val, tmp);
		  help(root->right, sum - root->val, tmp);
	  }
  };