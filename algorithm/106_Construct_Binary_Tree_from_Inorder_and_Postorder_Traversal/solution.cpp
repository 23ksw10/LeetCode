#include <iostream>
#include <vector>



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
	TreeNode*help(vector<int>& inorder, int i1, int i2, vector<int>& postorder, int p1, int p2) {
		if (i1 >= i2 || p1 >= p2)return nullptr;
		TreeNode* root = new TreeNode(postorder[p2 - 1]);
		auto it = find(inorder.begin() + i1, inorder.begin() + i2, postorder[p2 - 1]);
		int dif = it - inorder.begin() - i1;
		root->left = help(inorder, i1, i1 + dif, postorder, p1, p1 + dif);
		root->right = help(inorder, i1 + dif + 1, i2, postorder, p1 + dif, p2 - 1);
		return root;
	}
	TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
		int n = inorder.size();
		if (!n)return nullptr;
		help(inorder, 0, n, postorder, 0, n);
		return help(inorder, 0, n, postorder, 0, n);
	}
};