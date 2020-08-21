#include <iostream>
#include <vector>
#include <unordered_set>



using namespace std;

class Solution {
public:
	bool isHappy(int n) {
		unordered_set<int>s;
		int happyN = 0;
		int tmp;
		while (1) {
			while (n) {

				tmp = n % 10;
				tmp *= tmp;
				happyN += tmp;
				n /= 10;
			}
			if (happyN == 1)return true;
			if (s.find(happyN) != s.end())return false;
			s.insert(happyN);
			n = happyN;
			happyN = 0;
			cout << happyN << endl;
		}

		return true;
	}
};