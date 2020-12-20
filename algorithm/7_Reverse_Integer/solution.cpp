#include <iostream>
#include <queue>


using namespace std;




 
class Solution {
public:
	int reverse(int x) {
		if (x > -10 && x < 10)return x;
		queue<long long>q;
		long long tmp = x;
		while (tmp) {
			q.push(tmp % 10);
			tmp /= 10;
		}
		long long ans = 0;
		while (!q.empty()) {
			ans *= 10;
			ans += q.front();
			q.pop();
		}
		if (ans > INT_MAX || ans < INT_MIN)return 0;
		return ans;
	}
};