#include <iostream>
#include <vector>
#include <unordered_map>



using namespace std;

class Node {
public:
	int val;
	vector<Node*> neighbors;
	Node() {
		val = 0;
		neighbors = vector<Node*>();
	}
	Node(int _val) {
		val = _val;
		neighbors = vector<Node*>();
	}
	Node(int _val, vector<Node*> _neighbors) {
		val = _val;
		neighbors = _neighbors;
	}
};


class Solution {
public:
	unordered_map<Node*, Node*>m;
	void dfs(Node* node, Node* ans) {
		for (auto &a : node->neighbors) {
			if (m.find(a) == m.end()) {
				Node* ans = new Node(a->val, {});
				m[a] = ans;
				dfs(a, ans);
			}
			ans->neighbors.push_back(m[a]);
		}
	}
	Node* cloneGraph(Node* node) {
		if (!node)return nullptr;
		Node* ans = new Node(node->val, {});
		m[node] = ans;
		dfs(node, ans);
		return ans;
	}
};