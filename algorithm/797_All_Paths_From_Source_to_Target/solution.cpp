#include <iostream>
#include <vector>


using namespace std;



class Solution {
public:
	vector<vector<int>> allPathsSourceTarget(vector<vector<int>>& graph) {
		vector<vector<int>> ans;
		vector<int> a;
		help(a, ans, graph, 0);
		return ans;




	}
	void help(vector<int>a, vector<vector<int>> &ans, vector<vector<int>>graph, int i)
	{
		a.push_back(i);
		for (int j = 0; j < graph[i].size(); j++)
		{
			help(a, ans, graph, graph[i][j]);

		}

		if (a.back() == graph.size() - 1)
		{
			ans.push_back(a);
		}

	}
};