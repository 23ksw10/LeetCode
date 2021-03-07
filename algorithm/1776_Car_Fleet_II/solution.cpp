#include <iostream>
#include <vector>
#include <stack>





using namespace std;


 
class Solution {
public:
	vector<double> getCollisionTimes(vector<vector<int>>& cars) {
		int n = cars.size();
		vector<double> res(n, 0);
		stack<int> s;
		for (int i = n - 1; i >= 0; --i) {

			while (s.size() && cars[s.top()].back() >= cars[i].back()) s.pop();
			double time = -1;
			while (s.size()) {
				time = 1.0 * (cars[s.top()].front() - cars[i].front()) / (cars[i].back() - cars[s.top()].back());
				if (res[s.top()] == -1 || time <= res[s.top()]) break;

				s.pop();
			}
			res[i] = time;
			s.push(i);
		}
		return res;
	}
};