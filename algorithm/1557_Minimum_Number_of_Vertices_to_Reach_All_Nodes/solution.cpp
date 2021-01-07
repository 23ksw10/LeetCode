#include <iostream>
#include <vector>





using namespace std;



class Solution {
public:
	vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
		vector<int>ans;
		vector<int>nodes(n, 0);
		for (auto &e : edges) {
			nodes[e[1]] = 1;
		}
		for (int i = 0; i < n; i++) {
			if (nodes[i] == 0)ans.push_back(i);
		}
		return ans;
	}
};