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
	int findBottomLeftValue(TreeNode* root) {
		int ans;
		if (root)
		{
			ans = root->val;
			int maxdepth = 0;
			help(root->left, 1, maxdepth, ans);
			help(root->right, 1, maxdepth, ans);
		}

		return ans;

	}
	void help(TreeNode* root, int depth, int &maxdepth, int &ans)
	{

		if (root)
		{
			if (depth > maxdepth)
			{
				ans = root->val;
				maxdepth = depth;
			}
			help(root->left, depth + 1, maxdepth, ans);
			help(root->right, depth + 1, maxdepth, ans);
		}

	}
};