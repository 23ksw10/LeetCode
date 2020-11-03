#include <iostream>
#include <vector>






using namespace std;


class MyCalendar {
public:
	vector<pair<int, int>>days;
	MyCalendar() {

	}

	bool book(int start, int end) {
		for (auto a : days) {
			if (!(a.second <= start || a.first >= end))return false;
		}
		days.push_back({ start,end });
		return true;
	}
};