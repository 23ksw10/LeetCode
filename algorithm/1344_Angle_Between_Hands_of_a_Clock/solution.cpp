#include <iostream>





using namespace std;




class Solution {
public:
	double angleClock(int hour, int minutes) {
		double hAngle = hour * 30 + minutes * 0.5;
		if (hAngle >= 360) hAngle -= 360;
		double mAngle = minutes * 6;

		double ans = abs(hAngle - mAngle);
		if (ans > 180) ans = 360 - ans;
		return ans;

	}
};