#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


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
	vector<int> largestValues(TreeNode* root) {
		vector<int> ans;
		queue< TreeNode* >q;
		if (root)
		{
			q.push(root);
		}
		while (!q.empty())
		{
			int a = INT_MIN;

			int s = q.size();
			for (int i = 0; i < s; i++)
			{
				auto t = q.front();
				a = max(t->val, a);
				if (t->left)q.push(t->left);
				if (t->right)q.push(t->right);
				q.pop();
			}
			ans.push_back(a);
		}

		return ans;
	}

};