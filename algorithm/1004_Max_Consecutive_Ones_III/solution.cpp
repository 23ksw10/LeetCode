#include <iostream>
#include <vector>
#include<algorithm>



using namespace std;




class Solution {
public:
	int longestOnes(vector<int>& A, int K) {
		int start = 0, longest = 0, zeros = 0;
		for (int end = 0; end < A.size(); end++) {
			if (A[end] == 0) { zeros++; }
			while (zeros > K) {
				if (A[start] == 0) { zeros--; }
				start++;
			}
			longest = max(longest, end + 1 - start);
		}
		return longest;
	}
};