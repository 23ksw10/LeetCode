#include <iostream>
#include <vector>
#include<unordered_map>

using namespace std;



class Solution {
public:
	vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		vector<vector<int>> answer;
		unordered_map<int, vector<int>> m;
		for (int i = 0; i < groupSizes.size(); i++)
		{

			int key = groupSizes[i];
			if (m[key].size() > 0)
			{
				m[key].push_back(i);
			}
			else
				m[key] = vector<int>{ i };
			if (m[key].size() == key)
			{
				answer.push_back(m[key]);
				m.erase(key);
			}
		}
		return answer;

	}
};