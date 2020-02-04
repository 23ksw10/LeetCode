#include <iostream>
#include<vector>



using namespace std;




class Node {
public:
	int val;
	vector<Node*> children;

	Node() {}

	Node(int _val) {
		val = _val;
	}

	Node(int _val, vector<Node*> _children) {
		val = _val;
		children = _children;
	}
};

class Solution {
private:
	vector<int> ans;
public:
	vector<int> preorder(Node* root) {

		if (root != NULL) ans.push_back(root->val);

		else return {};
		for (int i = 0; i < (root->children).size(); i++)
		{
			preorder(root->children[i]);
		}
		return ans;


	}
};
