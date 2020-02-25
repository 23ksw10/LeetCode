#include <iostream>
#include <string>



using namespace std;



class Solution {
public:
	string addStrings(string num1, string num2) {
		string ans;

		int n1 = num1.size() - 1;
		int n2 = num2.size() - 1;
		int sum = 0;
		while (n1 >= 0 || n2 >= 0 || sum > 0)
		{

			if (n1 >= 0) sum += (num1[n1--] - '0');
			if (n2 >= 0) sum += (num2[n2--] - '0');

			ans.insert(0, 1, (sum % 10) + '0');
			sum /= 10;



		}


		return ans;

	}
};