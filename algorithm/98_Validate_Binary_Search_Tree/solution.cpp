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

	bool check(TreeNode* root, long long int minn, long long int maxx) {

		if (root == NULL)
			return true;

		if (root->val<minn || root->val>maxx)
			return false;


		return check(root->left, minn, (long long int)root->val - 1) && check(root->right, (long long int)root->val + 1, maxx);

	}

	bool isValidBST(TreeNode* root) {

		return check(root, INT_MIN, INT_MAX);
	}
};