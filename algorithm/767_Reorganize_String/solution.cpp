#include <iostream>
#include <vector>
#include <string>


using namespace std;

  
class Solution {
public:
	string reorganizeString(string S) {
		vector<int>cnt(26, 0);
		int max_alp = 0;
		int i = 0;
		for (auto c : S) {
			if (cnt[max_alp] < ++cnt[c - 'a']) {
				max_alp = c - 'a';
			}
		}
		if (cnt[max_alp] * 2 - 1 > S.size()) return "";
		while (cnt[max_alp]) {
			S[i] = 'a' + max_alp;
			i += 2;
			cnt[max_alp]--;
		}
		for (int j = 0; j < 26; j++) {
			while (cnt[j]) {
				if (i >= S.size()) {
					i = 1;
				}
				S[i] = 'a' + j;
				i += 2;
				cnt[j]--;
			}
		}
		return S;


	}
};