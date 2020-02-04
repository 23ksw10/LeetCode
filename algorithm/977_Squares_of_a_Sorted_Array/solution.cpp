#include <iostream>
#include<vector>


using namespace std;

class Solution {
public:
	vector<int> sortedSquares(vector<int>& A) {
		vector<int> x(A.size());
		int i = 0, j = A.size() - 1, k = j;
		while (k >= 0) {
			int a = A[i] * A[i], b = A[j] * A[j];
			if (a <= b) j--, x[k--] = b;
			else i++, x[k--] = a;
		}
		return x;
	}
};
};

