#include <iostream>
#include <vector>
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
	vector<double> averageOfLevels(TreeNode* root) {
		vector<double> ans;
		queue<TreeNode* > count;
		count.push(root);
		while (!count.empty())
		{

			int s = count.size();
			double v = 0;

			for (int i = 0; i < s; i++)
			{
				TreeNode*a = count.front();
				if (a->left)count.push(a->left);
				if (a->right)count.push(a->right);
				v += a->val;
				count.pop();


			}
			ans.push_back((double)v / s);
		}

		return ans;

	}

};
