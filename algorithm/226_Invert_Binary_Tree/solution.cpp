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
	TreeNode* invertTree(TreeNode* root) {
		TreeNode *a;
		if (!root) return root;
		a = root->left;
		root->left = root->right;
		root->right = a;
		invertTree(root->left);
		invertTree(root->right);

		return root;


	}
};