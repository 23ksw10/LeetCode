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
	TreeNode* help(vector<int>& nums, int l, int r) {
		if (l > r) return nullptr;
		int m = l + (r - l) / 2;
		TreeNode *answer = new TreeNode(nums[m]);
		answer->left = help(nums, l, m - 1);
		answer->right = help(nums, m + 1, r);
		return answer;






	}

	TreeNode* sortedArrayToBST(vector<int>& nums) {
		int r = nums.size() - 1;
		return help(nums, 0, r);

	}
};