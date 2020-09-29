#include <iostream>





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
	int ans = 0;
	void help(TreeNode* root, int tmt) {
		if (!root)return;
		if (!(root->left) && !(root->right)) {
			tmt = tmt * 10 + root->val;
			ans += tmt;
			return;
		}
		tmt = tmt * 10 + root->val;
		help(root->left, tmt);
		help(root->right, tmt);
	}
	int sumNumbers(TreeNode* root) {
		if (!root) return 0;
		help(root, 0);
		return ans;

	}
};