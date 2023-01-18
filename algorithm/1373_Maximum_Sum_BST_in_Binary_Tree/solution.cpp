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
	int ans = 0;
	tuple<int, int, int> check(TreeNode* root) {
		if (!root)return { INT_MAX,INT_MIN,0 };
		auto[a, b, c] = check(root->left);
		auto[d, e, f] = check(root->right);
		if (root->val<d&&root->val>b) {
			ans = max(ans, c + f + root->val);
			return { min(a,root->val),max(root->val,e),c + f + root->val };
		}
		return { INT_MIN,INT_MAX,0 };
	}
	int maxSumBST(TreeNode* root) {
		check(root);
		return ans;
	}
};

