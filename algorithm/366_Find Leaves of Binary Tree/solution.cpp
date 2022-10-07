#include <iostream>
#include <vector>
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
	vector<vector<int>>ans;
	int dfs(TreeNode* root, int depth) {
		if (!root)return depth + 1;
		depth = max(dfs(root->left, depth), dfs(root->right, depth));
		if (depth > ans.size()) {
			ans.push_back({});
		}
		ans[depth - 1].push_back(root->val);
		return depth + 1;
	}
	vector<vector<int>> findLeaves(TreeNode* root) {
		dfs(root, 0);
		return ans;
	}
};