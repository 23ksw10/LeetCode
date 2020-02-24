#include <iostream>
#include <vector>
#include <algorithm>
#include <map>


using namespace std;



class Solution {
public:
	int maxNumberOfBalloons(string text) {
		map<char, double>m;

		for (auto s : text)
		{
			switch (s)
			{

			case'b':
				++m[s];
				break;
			case'a':
				++m[s];
				break;
			case'l':
				m[s] += 0.5;
				break;
			case'o':
				m[s] += 0.5;
				break;
			case'n':
				++m[s];
				break;
			}
		}
		double ans = m['b'];
		for (auto it = m.begin(); it != m.end(); it++)
		{
			ans = min(it->second, ans);
		}
		return (int)ans;
	}
};