#include <iostream>
#include <vector>
#include<algorithm>

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
	vector<int> getAllElements(TreeNode* root1, TreeNode* root2) {
		vector<int> ans;
		helper(ans, root1);
		helper(ans, root2);
		sort(ans.begin(), ans.end());


		return ans;




	}
	void helper(vector<int> &ans, TreeNode* root1)
	{
		if (root1)
			ans.push_back(root1->val);
		else
			return;
		if (root1->left&&root1->right)
		{
			helper(ans, root1->left);
			helper(ans, root1->right);
		}
		else if (root1->left)
			helper(ans, root1->left);
		else if (root1->right)
			helper(ans, root1->right);
		else
			return;




	}
};