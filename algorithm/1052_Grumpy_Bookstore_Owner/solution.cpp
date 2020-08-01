#include <iostream>
#include <vector>
#include<string>
#include<algorithm>



using namespace std;



class Solution {
public:
	int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int X) {
		int more_satisfied_customers = 0;
		int answer = 0;
		int temp = 0;
		for (int i = 0; i < grumpy.size(); i++) {
			if (!grumpy[i])answer += customers[i];
			else temp += customers[i];
			if (i >= X && grumpy[i - X]) temp -= customers[i - X];
			more_satisfied_customers = max(more_satisfied_customers, temp);

		}


		return answer + more_satisfied_customers;
	}
};