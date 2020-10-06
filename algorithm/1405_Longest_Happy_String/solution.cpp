#include <iostream>
#include <string>
#include <queue>


using namespace std;

class Solution {
public:
	string longestDiverseString(int a, int b, int c) {
		priority_queue<pair<int, char>>pq;
		if (a)pq.push({ a,'a' });
		if (b)pq.push({ b,'b' });
		if (c)pq.push({ c,'c' });
		string ans;
		while (pq.size() > 1) {
			auto a = pq.top(); pq.pop();
			auto b = pq.top(); pq.pop();
			if (a.first >= 2) {
				ans = ans + a.second + a.second;
				a.first -= 2;
			}
			else {
				ans = ans + a.second;
				a.first -= 1;
			}
			if (b.first >= 2 && b.first >= a.first) {
				ans = ans + b.second + b.second;
				b.first -= 2;
			}
			else {
				ans = ans + b.second;
				b.first -= 1;
			}
			if (a.first > 0)pq.push(a);
			if (b.first > 0)pq.push(b);

		}
		if (pq.empty())return ans;
		auto f = pq.top();
		if (f.first > 1)ans = ans + f.second + f.second;
		else ans = ans + f.second;
		return ans;
	}
};