#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <unordered_map>
#include <unordered_set>



using namespace std;


 

class Solution {
public:
	unordered_map<string, double>m;
	vector<pair<double, int>>v[40];
	double dfs(int start, int end, double value, set<int>check) {
		double ans = -1;
		for (int i = 0; i < v[start].size(); i++) {
			if (v[start][i].second == end)return value * v[start][i].first;
			else {
				if (check.find(v[start][i].second) == check.end()) {
					check.insert(v[start][i].second);
					ans = dfs(v[start][i].second, end, value*v[start][i].first, check);
					if (ans != -1) break;
				}

			}

		}
		return ans;
	}
	vector<double> calcEquation(vector<vector<string>>& equations, vector<double>& values, vector<vector<string>>& queries) {
		vector<double>ans;
		int n = equations.size();
		unordered_set<string>s;
		for (int i = 0; i < n; i++) {
			s.insert(equations[i][0]);
			s.insert(equations[i][1]);
		}
		int k = s.size();
		int a = 0;
		for (auto it = s.begin(); it != s.end(); it++) {
			m[*it] = a;
			a++;
		}
		for (int i = 0; i < n; i++) {
			int c = m[equations[i][0]];
			int d = m[equations[i][1]];
			v[c].push_back({ 1 / values[i],d });
			v[d].push_back({ values[i],c });
		}
		for (int i = 0; i < queries.size(); i++) {
			if (!m.count(queries[i][0]) || !m.count(queries[i][1]))ans.push_back(-1);
			else {
				int c = m[queries[i][0]];
				int d = m[queries[i][1]];
				if (c == d) {
					ans.push_back(1);
					continue;
				}

				set<int>st;
				st.insert(d);
				ans.push_back(dfs(d, c, 1.0, st));


			}
		}
		return ans;
	}
};