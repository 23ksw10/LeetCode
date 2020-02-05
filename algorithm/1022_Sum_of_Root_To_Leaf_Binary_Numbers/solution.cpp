#include <iostream>
#include <stack>



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

	int sumRootToLeaf(TreeNode* root) {
		int n = 0;
		dfs(root, n);
		return sum;
	}
	int sum = 0;

	void dfs(TreeNode *root, int val)
	{
		stack<TreeNode*>st;
		st.push(root);

		while (!st.empty())
		{

			TreeNode * node = st.top();

			st.pop();

			if (node == NULL)
				return;

			val = val << 1 | root->val;

			if (root->left == NULL && root->right == NULL)
				sum += val;

			if (root->left)
				dfs(root->left, val);

			if (root->right)
				dfs(root->right, val);

		}
	}

};