#pragma once
class Complex {
	float r, i;

public:
	void setr(float val) {
		r = val;
	}
	void seti(float val) {
		i = val;
	}
	float getr() {
		return r;
	}
	float geti() {
		return i;
	}
	void print() {
		if (r != 0)
		{
			cout << r;
			if (i > 0)
				cout << '+';
		}
		if (i != 0)
			cout << i << 'i';
		else if (r == 0)
			cout << r;
	}
};