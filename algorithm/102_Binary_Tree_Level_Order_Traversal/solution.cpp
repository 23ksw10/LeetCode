#include <iostream>
#include <vector>
#include <queue>





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
	vector<vector<int>> levelOrder(TreeNode* root) {
		if (!root)return {};
		vector<vector<int>>ans;
		queue<TreeNode *>q;
		q.push(root);
		while (!q.empty()) {
			int s = q.size();
			vector<int>tmp;
			for (int i = 0; i < s; i++) {
				auto a = q.front();
				q.pop();
				if (a->left)q.push(a->left);
				if (a->right)q.push(a->right);
				tmp.push_back(a->val);

			}
			ans.push_back(tmp);
		}
		return ans;
	}
};