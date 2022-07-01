#include <iostream>
#include <algorithm>
#include <tuple>


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
	tuple<int, int, int> help(TreeNode* root) {
		if (!root) {
			return { 1,0,0 };
		}
		auto [lci, lcc, ln] = help(root->left);
		auto [rci, rcc, rn] = help(root->right);
		int cci = min({ lci,ln,lcc }) + min({ rci,rn,rcc }) + 1;
		int ccc = min({ lci + rcc,rci + lcc,lci + rci });
		int cn = lcc + rcc;
		return { cci,ccc,cn };
	}
	int minCameraCover(TreeNode* root) {
		auto [a, b, c] = help(root);
		return min(a, b);
	}
};