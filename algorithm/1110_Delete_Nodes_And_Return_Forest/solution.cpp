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
	  vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
		  vector<TreeNode*>ans;
		  help(root, to_delete, ans, true);
		  return ans;
	  }
	  TreeNode* help(TreeNode* root, vector<int>& to_delete, vector<TreeNode*>&ans, bool start) {
		  if (!root) return nullptr;
		  TreeNode* tmp = root;
		  if (find(to_delete.begin(), to_delete.end(), root->val) == to_delete.end()) {
			  tmp->left = help(root->left, to_delete, ans, false);
			  tmp->right = help(root->right, to_delete, ans, false);
		  }
		  else {
			  help(root->left, to_delete, ans, true);
			  help(root->right, to_delete, ans, true);
			  return nullptr;
		  }
		  if (start)ans.push_back(root);
		  return root;
	  }
  };