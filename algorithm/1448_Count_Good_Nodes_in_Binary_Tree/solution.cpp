#include <iostream>




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
	int help(TreeNode* root, int n) {
		if (!root)return 0;
		if (root->val >= n)return 1 + help(root->left, root->val) + help(root->right, root->val);
		return help(root->left, n) + help(root->right, n);
	}
	int goodNodes(TreeNode* root) {
		if (!root) return 0;
		return 1 + help(root->left, root->val) + help(root->right, root->val);
	}
};