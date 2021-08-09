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
	pair<int, int> dfs(TreeNode* root) {
		if (!root)return { 0,0 };

		auto tmp1 = dfs(root->left);
		auto tmp2 = dfs(root->right);
		pair<int, int> tmp = { tmp1.first + tmp2.first,tmp1.second + tmp2.second };
		tmp.second += root->val;
		if (tmp.first > tmp.second) {
			tmp.second = tmp.first;
		}
		else swap(tmp.first, tmp.second);
		return tmp;

	}
	int rob(TreeNode* root) {
		auto ans = dfs(root);
		return max(ans.first, ans.second);
	}
};