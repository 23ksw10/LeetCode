#include <iostream>
#include <vector>
#include <queue>
#include <unordered_set>


using namespace std;


 
 
class Solution {
public:
	int openLock(vector<string>& deadends, string target) {
		int n = deadends.size();
		unordered_set<string>visit(deadends.begin(), deadends.end());
		if (visit.find("0000") != visit.end())return -1;
		queue<pair<string, int>>q;
		q.push({ "0000",0 });
		visit.insert("0000");
		while (!q.empty()) {
			int size = q.size();
			for (int i = 0; i < size; i++) {
				auto [s, moves] = q.front();
				q.pop();
				if (s == target)return moves;
				for (int i = 0; i < 4; i++) {
					string tmp_up = s;
					string tmp_down = s;
					tmp_up[i] = (s[i] == '9' ? '0' : s[i] + 1);
					tmp_down[i] = (s[i] == '0' ? '9' : s[i] - 1);
					if (visit.find(tmp_up) == visit.end()) {
						q.push({ tmp_up,moves + 1 });
						visit.insert(tmp_up);
					}
					if (visit.find(tmp_down) == visit.end()) {
						q.push({ tmp_down,moves + 1 });
						visit.insert(tmp_down);
					}
				}
			}
		}
		return -1;
	}
};