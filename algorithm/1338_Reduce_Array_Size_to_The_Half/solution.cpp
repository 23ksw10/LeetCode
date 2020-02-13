#include <iostream>
#include <vector>
#include <map>

#include <algorithm>
using namespace std;



class Solution {
public:
	int minSetSize(vector<int>& arr) {
		int ans = 0;
		vector<int>a;
		int check = 0;
		map<int, int> m;
		sort(arr.begin(), arr.end());
		for (int i = 0; i < arr.size(); i++)
		{
			++m[arr[i]];
		}
		auto it = m.begin();
		for (it; it != m.end(); it++)
		{
			a.push_back(it->second);
		}
		sort(a.begin(), a.end(), greater<int>());
		for (int i = 0; i < a.size(); i++)
		{
			check += a[i];
			if (check >= (arr.size() / 2))
			{
				ans = i + 1;
				break;
			}
		}
		return ans;
	}
};