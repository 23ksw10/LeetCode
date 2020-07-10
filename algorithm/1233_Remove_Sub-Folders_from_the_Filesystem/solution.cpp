#include <iostream>
#include <vector>
#include<string>
#include<unordered_set>
#include<algorithm>


using namespace std;




class Solution {
public:
	vector<string> removeSubfolders(vector<string>& folder) {
		unordered_set<string>folderSet(folder.begin(), folder.end());
		vector<string>ans;
		int i, j;
		sort(folder.begin(), folder.end());
		for (i = 0; i < folder.size(); i++) {
			bool b = true;
			for (j = 1; j < folder[i].size(); j++) {
				if (folder[i][j] != '/') continue;
				if (folderSet.find(folder[i].substr(0, j)) != folderSet.end()) {
					b = false;
					break;
				}
			}
			if (b)ans.push_back(folder[i]);


		}

		return ans;
	}
};