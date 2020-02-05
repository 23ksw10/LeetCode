#include <iostream>

using namespace std;



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
	int Sum = 0;
	TreeNode* bstToGst(TreeNode* root) {
		if (!root->left && !root->right)
		{
			Sum += root->val;
			root->val = Sum;

		}
		else if (!root->left)

		{
			bstToGst(root->right);
			Sum += root->val;
			root->val = Sum;
		}
		else if (!root->right)
		{
			Sum += root->val;
			root->val = Sum;
			bstToGst(root->left);

		}
		else
		{
			bstToGst(root->right);
			Sum += root->val;
			root->val = Sum;
			bstToGst(root->left);

		}
		return root;


	}
};