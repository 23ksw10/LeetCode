#include <iostream>
#include <vector>
#include<string>
#include<algorithm>



using namespace std;



class Solution {
public:
	int numberOfSubstrings(string s) {
		vector<int>c = { -1,-1,-1 };
		int ans = 0;
		for (int i = 0; i < s.size(); i++) {
			c[s[i] - 'a'] = i;
			ans += min({ c[0],c[1],c[2] }) + 1;
		}
		return ans;
	}
};