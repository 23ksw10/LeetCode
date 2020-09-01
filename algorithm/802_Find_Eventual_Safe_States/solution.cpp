#include <iostream>
#include <vector>







using namespace std;




class Solution {
public:
	bool dfs(vector<vector<int>>& graph, int v, vector<int>& vis) {
		if (vis[v] != 0)
			return vis[v] == 1;
		vis[v] = 2;
		for (auto it = graph[v].begin(); it != graph[v].end(); it++)
			if (!dfs(graph, *it, vis))
				return false;
		vis[v] = 1;
		return true;
	}
	vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
		int n = graph.size();
		vector<int>res;
		vector<int>vis(n, 0);
		for (int i = 0; i < n; i++) {
			if (dfs(graph, i, vis))
				res.push_back(i);
		}
		return res;
	}
};