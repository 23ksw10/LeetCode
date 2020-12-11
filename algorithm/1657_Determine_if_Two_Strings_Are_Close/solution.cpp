#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;






class Solution {
public:
	bool closeStrings(string word1, string word2) {
		if (word1.size() != word2.size())return false;
		vector<int>c(26, 0);
		vector<int>c1(26, 0);
		for (int i = 0; i < word1.size(); i++) {
			c[word1[i] - 'a']++;
			c1[word2[i] - 'a']++;
		}
		multiset<char>s;
		multiset<char>s1;
		for (int i = 0; i < 26; i++) {
			if (c[i] > 0)s.insert('a' + i);
			if (c1[i] > 0)s1.insert('a' + i);
		}
		sort(c.begin(), c.end());
		sort(c1.begin(), c1.end());
		return s == s1 && c == c1 ? true : false;
	}
};
};