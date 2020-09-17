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
	TreeNode *a = nullptr;
	void flatten(TreeNode* root) {
		if (root) {
			TreeNode*tmt = root->right;
			if (a) {
				a->right = root;
			}
			a = root;
			flatten(root->left);
			root->left = nullptr;
			flatten(tmt);
		}
	}
};