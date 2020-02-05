#include <iostream>
#include <vector>
#include <algorithm>



using namespace std;




class Solution {
public:
	vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
		int min = INT_MAX;
		vector<vector<int>> ans;
		sort(arr.begin(), arr.end());
		for (int i = 0; i < arr.size() - 1; i++)
		{

			if (abs(arr[i + 1] - arr[i]) < min)
				min = abs(arr[i + 1] - arr[i]);

		}
		for (int i = 0; i < arr.size() - 1; i++)
		{

			vector<int>ans1;
			if (abs(arr[i + 1] - arr[i]) == min)
			{
				if (arr[i + 1] < arr[i])
				{
					ans1.push_back(arr[i + 1]);
					ans1.push_back(arr[i]);
					ans.push_back(ans1);
				}
				else
				{
					ans1.push_back(arr[i]);
					ans1.push_back(arr[i + 1]);
					ans.push_back(ans1);
				}
			}



		}
		
		return ans;
	}
};
