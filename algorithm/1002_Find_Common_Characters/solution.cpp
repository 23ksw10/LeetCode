#include <iostream>
#include <vector>
#include <string>
#include <algorithm>


using namespace std;




class Solution {
public:
	vector<string> commonChars(vector<string>& A) {
		vector<int>cnt(26, 99999999);
		vector<string>ans;
		for (auto s : A) {
			vector<int>c1(26, 0);
			for (auto c : s)
				++c1[c - 'a'];
			for (int i = 0; i < 26; i++)
				cnt[i] = min(cnt[i], c1[i]);


		}
		for (int i = 0; i < 26; i++)
		{
			for (int j = 0; j < cnt[i]; j++)
			{
				ans.push_back(string(1, i + 'a'));
			}
		}
		return ans;

	}
};
