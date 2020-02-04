#include <iostream>
#include<vector>



using namespace std;

class Solution {
public:
	int repeatedNTimes(vector<int>& A) {
		for (int i = 0; i < A.size(); i++) {
			std::vector<int>::iterator it = find(A.begin(), A.end(), A[i]);
			if (find(it + 1, A.end(), A[i]) != A.end()) {
				return A[i];
			}
		}
		return -1;
	}
};

