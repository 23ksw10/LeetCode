#include <iostream>


using namespace std;







 
  struct TreeNode {
      int val;
      TreeNode *left;
      TreeNode *right;
      TreeNode(int x) : val(x), left(NULL), right(NULL) {}
  };
 
class Solution {
public:
	TreeNode *ans;
	int check(TreeNode* root, TreeNode* p, TreeNode* q) {
		if (!root) return 0;
		int result = (root == p || root == q) + check(root->left, p, q) + check(root->right, p, q);
		if (result == 2 && !ans) ans = root;
		return result;



	}
	TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
		check(root, p, q);
		return ans;
	}
};