#include <iostream>
#include <vector>


using namespace std;



/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
	vector<int> numbers;
	void kthSmallestHelp(TreeNode* root, int k) {
		if (numbers.size() == k) return;
		if (!root) return;
		if (root->left) {
			kthSmallestHelp(root->left, k);
		}
		numbers.push_back(root->val);
		if (root->right) {
			kthSmallestHelp(root->right, k);
		}


	}
	int kthSmallest(TreeNode* root, int k) {
		kthSmallestHelp(root, k);
		return numbers[k - 1];


	}
};