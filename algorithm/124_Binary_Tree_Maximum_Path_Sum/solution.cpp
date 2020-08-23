#include <iostream>
#include <algorithm>






using namespace std;




  struct TreeNode {
      int val;
     TreeNode *left;
     TreeNode *right;
      TreeNode() : val(0), left(nullptr), right(nullptr) {}
      TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
  };
 
class Solution {
public:
	int help(TreeNode* root, int &sum) {
		if (!root) return 0;
		int l = max(help(root->left, sum), 0);
		int r = max(help(root->right, sum), 0);
		sum = max(sum, l + r + root->val);
		return max({ l + root->val,r + root->val });
	}
	int maxPathSum(TreeNode* root) {
		int sum = -1000000;
		help(root, sum);

		return sum;
	}
};