#include <iostream>
#include <string>






using namespace std;




class Solution {
public:
	bool isLongPressedName(string name, string typed) {
		int i = 0;
		int j = 0;
		int tmp = 0;
		while (i < name.size() && j < typed.size()) {
			int count = 1;
			while (i + 1 < name.size() && name[i] == name[i + 1]) {
				i++;
				count++;
			}
			int count2 = 1;
			if (typed[j] != name[i])return false;

			while (j + 1 < typed.size() && typed[j] == typed[j + 1]) {
				j++;
				count2++;
			}
			if (count > count2)return false;
			i++;
			j++;
		}
		if (i != name.size() || j != typed.size())return false;
		return true;
	}
};