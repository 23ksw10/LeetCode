#include <iostream>
#include<vector>


using namespace std;

class Solution {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		for (size_t i = 0; i < A.size(); i++)
		{
			if (A[i]<A[i + 1] && A[i + 1]>A[i + 2])
				return i + 1;
		}
		return -1;
	}
};
