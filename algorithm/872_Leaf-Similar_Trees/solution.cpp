#include <iostream>
#include <vector>



using namespace std;



class Solution {
public:
	vector<int>r1;
	vector<int>r2;
	bool leafSimilar(TreeNode* root1, TreeNode* root2) {
		return leafSimilarCheck1(root1) == leafSimilarCheck2(root2);



	}
	vector<int> leafSimilarCheck1(TreeNode* root1)
	{

		if ((root1->left == NULL && root1->right == NULL))
		{
			int ab = root1->val;
			r1.push_back(ab);
		}
		else
		{
			if (!(root1->right))
				leafSimilarCheck1(root1->left);
			else if (!(root1->left))
				leafSimilarCheck1(root1->right);
			else
			{
				leafSimilarCheck1(root1->left);
				leafSimilarCheck1(root1->right);
			}
		}
		return r1;
	}
	vector<int> leafSimilarCheck2(TreeNode* root1)
	{

		if ((root1->left == NULL && root1->right == NULL))
		{
			int ab = root1->val;
			r2.push_back(ab);
		}
		else
		{
			if (!(root1->right))
				leafSimilarCheck2(root1->left);
			else if (!(root1->left))
				leafSimilarCheck2(root1->right);
			else
			{
				leafSimilarCheck2(root1->left);
				leafSimilarCheck2(root1->right);
			}
		}
		return r2;
	}


};
