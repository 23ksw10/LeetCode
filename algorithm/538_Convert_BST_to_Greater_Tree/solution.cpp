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
	TreeNode* convertBST(TreeNode* root) {
		int v = 0;

		help(root, v);
		return root;

	}
	void help(TreeNode* root, int &v)
	{
		if (root)
		{
			help(root->right, v);
			root->val += v;
			v = root->val;
			help(root->left, v);
		}
		else v += 0;

	}
};