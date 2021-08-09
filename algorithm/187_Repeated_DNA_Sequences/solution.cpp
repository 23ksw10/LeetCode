#include <iostream>
#include <unordered_map>
#include <vector>




using namespace std;


 
 
class Solution {
public:
	vector<string> findRepeatedDnaSequences(string s) {
		vector<string>ans;
		if (s.size() < 10)return ans;
		unordered_map<string, int>m;
		for (int i = 0; i < 10; i++) {
			for (int j = i; j <= s.size() - 10; j += 10) {
				auto t = s.substr(j, 10);
				if (m.count(t) == 0)m[t]++;
				else {
					if (m[t] == 1) {
						ans.push_back(t);
						m[t]++;
					}
				}
			}
		}
		return ans;

	}
};