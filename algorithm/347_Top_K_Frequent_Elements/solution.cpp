#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>


using namespace std;



class Solution {
public:
	vector<int> topKFrequent(vector<int>& nums, int k) {
		vector<int>ans;
		unordered_map<int, int>m;
		for (int i = 0; i < nums.size(); i++)
		{
			m[nums[i]]++;
		}
		vector<pair<int, int>>arr;
		for (auto it = m.begin(); it != m.end(); it++)
		{
			arr.push_back(make_pair(it->second, it->first));
		}
		m.clear();
		sort(arr.begin(), arr.end());
		for (int i = arr.size() - 1; k > 0; k--, i--)
		{
			ans.push_back(arr[i].second);
		}
		return ans;

	}
};