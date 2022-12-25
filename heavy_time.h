#pragma once
class heavyTime {

	int hr, min, sec;

public:
	void sethr(int val) {
		if (val >= 0 and val < 24)
			hr = val;
		else
			hr = 0;
	}
	void setmin(int val) {
		if (val >= 0 and val < 60)
			min = val;
		else
			min = 0;
	}
	void setsec(int val) {
		if (val >= 0 and val < 60)
			sec = val;
		else
			sec = 0;
	}

	int gethr() {
		return hr;
	}
	int getmin() {
		return min;
	}
	int getsec() {
		return sec;
	}

	void printUniversal() {
		cout << hr << ':' << min << ':' << sec;
	}
	void printStandard() {
		cout << (hr >= 12 ? (hr - 12) : hr) << ':' << min << ':' << sec << (hr >= 12 ? " PM" : " AM");
	}
};