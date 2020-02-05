#include <iostream>
#include <algorithm>



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
	
	int maxDepth(TreeNode* root) {
		return check(root, 0);

	}
	int check(TreeNode* root, int depth)
	{
		if (root)
			depth++;
		else
			return depth;
		/*check(root->left, depth);
		check(root->right, depth);*/
		return max(check(root->left, depth), check(root->right, depth));

	}
};