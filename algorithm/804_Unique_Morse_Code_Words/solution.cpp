#include <iostream>
#include <string>
#include<vector>
#include<set>



using namespace std;

class Solution {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		vector<string> mos = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };

		string s = "";
		set<string> a;

		int ans = 0;
		for (int i = 0; i < words.size(); i++)
		{
			s = "";
			for (int j = 0; j < words[i].size(); j++)
			{
				s += mos[words[i][j] % 97];
			}
			a.insert(s);


		}

		return a.size();

	}
};
