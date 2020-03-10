#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


class Solution {
public:
	int largestPerimeter(vector<int>& A) {
		sort(A.begin(), A.end());
		int l = A.size();
		int a = A[l - 1];
		int b = A[l - 2];
		int c = A[l - 3];
		int i = 3;
		if (b + c > a)
			return a + b + c;
		while ((b + c <= a))
		{
			if (l == i)
				return 0;
			a = b;
			b = c;
			c = A[l - ++i];
		}
		return a + b + c;

	}
};