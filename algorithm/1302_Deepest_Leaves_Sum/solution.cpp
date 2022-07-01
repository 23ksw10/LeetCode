#include <iostream>
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
	  int deepestLeavesSum(TreeNode* root) {
		  queue<TreeNode* >q;
		  int ans = 0;
		  q.push(root);
		  while (q.size()) {
			  bool check = false;
			  int tmp = 0;
			  int s = q.size();
			  for (int i = 0; i < s; i++) {
				  auto a = q.front();
				  q.pop();
				  if (a) {
					  check = true;
					  tmp += a->val;
					  q.push(a->left);
					  q.push(a->right);
				  }
			  }
			  if (check)ans = tmp;
		  }
		  return ans;

	  }
  };