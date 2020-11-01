#include <iostream>
#include <vector>
#include <algorithm>





using namespace std;


class Solution {
public:
	int maxScore(vector<int>& cardPoints, int k) {
		int total = 0;
		for (int i = 0; i < cardPoints.size(); i++) {
			total += cardPoints[i];
		}
		int sub = cardPoints.size() - k;
		int tmp = 0;
		for (int i = 0; i < sub; i++) {
			tmp += cardPoints[i];
		}
		int ans = total - tmp;
		int j = 0;
		for (int i = sub; i < cardPoints.size(); i++) {
			tmp += cardPoints[i];
			tmp -= cardPoints[j++];
			ans = max(ans, total - tmp);
		}
		return ans;

	}
};