#include <iostream>
#include <vector>
#include <unordered_map>

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
private:
	unordered_map<int, int>m;
	int index = 0;
public:

	TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
		for (int i = 0; i < inorder.size(); i++) {
			m[inorder[i]] = i;
		}
		return help(preorder, inorder, 0, inorder.size() - 1);

	}
	TreeNode* help(vector<int>& preorder, vector<int>& inorder, int l, int r) {
		TreeNode* ans = new TreeNode;
		ans->val = preorder[index++];
		int pivot = m[ans->val];
		if (pivot > l)ans->left = help(preorder, inorder, l, pivot - 1);
		if (pivot < r)ans->right = help(preorder, inorder, pivot + 1, r);
		return ans;
	}
};