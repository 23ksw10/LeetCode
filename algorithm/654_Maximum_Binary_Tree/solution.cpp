#include <iostream>
#include <vector>

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
	TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
		return constructMaximumBinaryTreeHelper(nums, 0, nums.size() - 1);



	}
	TreeNode* constructMaximumBinaryTreeHelper(vector<int>& nums, int left, int right)
	{

		if (left > right)
			return NULL;
		int max = nums[left];
		int maxindex = left;
		for (int i = left; i <= right; i++)
		{
			if (max < nums[i])
			{
				max = nums[i];
				maxindex = i;
			}

		}
		TreeNode* node = new TreeNode(max);
		node->left = constructMaximumBinaryTreeHelper(nums, left, maxindex - 1);
		node->right = constructMaximumBinaryTreeHelper(nums, maxindex + 1, right);
		return node;
	}

};