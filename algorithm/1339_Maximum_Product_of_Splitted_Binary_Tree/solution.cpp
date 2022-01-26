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
	long long sum = 0;
	long long ans = 0;
	void help(TreeNode* root) {
		if (root) {
			sum += root->val;
			sum = sum % (int)(1e9 + 7);
			help(root->left);
			help(root->right);
		}
	}
	long long help2(TreeNode* root) {
		if (!root)return 0;
		long long k = root->val;
		k += help2(root->left);
		k += help2(root->right);
		ans = max(ans, ((sum - k)*k));
		return k;
	}
	int maxProduct(TreeNode* root) {
		help(root);
		help2(root);
		return ans % (int)(1e9 + 7);
	}
};