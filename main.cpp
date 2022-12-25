#include<iostream>
#include<fstream>
using namespace std;


#include "complex.h"
#include "heavy_time.h"


void Options_List() {

	cout << char(26) << " Following operations are compatible:\n"
		<< "\t1. Add two numbers.\n"
		<< "\t2. Subtract two numbers.\n"
		<< "\t3. Multiply two numbers.\n"
		<< "\t4. Divide two numbers.\n"
		<< "\t5. Conjugate of a numbers.\n"
		<< "\t6. Modulus of a numbers.\n"
		<< "\t7. Additive inverse of a numbers.\n"
		<< "\t8. Multiplicative inverse numbers.\n\n"
		<< char(26) << " Select an option: ";
}


void Load(Complex*& Cnums, int& size) {

	ifstream fin("input.txt");
	fin >> size;
	Cnums = new Complex[size];
	for (int i = 0; i < size; i++)
	{
		int a;
		fin >> a;
		Cnums[i].setr(a);
		fin >> a;
		Cnums[i].seti(a);
	}
}

void DisplayCnums(Complex* Cs, int size) {

	for (int i = 0; i < size; i++)
	{
		cout << char('a' + i) << ")  ";
		Cs[i].print();
		cout << endl;
	}
}

Complex Add(Complex C1, Complex C2) {

	Complex ans;
	ans.setr(C1.getr() + C2.getr());
	ans.seti(C1.geti() + C2.geti());

	return ans;
}

Complex Subtract(Complex C1, Complex C2) {

	Complex ans;
	ans.setr(C1.getr() - C2.getr());
	ans.seti(C1.geti() - C2.geti());

	return ans;
}

Complex Multiply(Complex C1, Complex C2) {

	Complex ans;
	ans.setr((C1.getr() * C2.getr()) - (C1.geti() * C2.geti()));
	ans.seti((C1.getr() * C2.geti()) + (C1.geti() * C2.getr()));

	return ans;
}

Complex Conjugate(Complex C) {

	C.seti(C.geti() * -1);
	return C;
}

Complex Divide(Complex C1, Complex C2) {

	Complex ans;

	ans = Conjugate(C2);
	ans = Multiply(C1, ans);

	float divisor = pow(C2.getr(), 2) + pow(C2.geti(), 2);
	ans.setr(ans.getr() / divisor);
	ans.seti(ans.geti() / divisor);

	return ans;
}

float Modulus(Complex C) {

	float ans;

	ans = pow(pow(C.getr(), 2) + pow(C.geti(), 2), 0.5);
	return ans;
}

Complex AddInverse(Complex C) {

	C.setr(C.getr() * -1);
	C.seti(C.geti() * -1);

	return C;
}

Complex MulInverse(Complex C) {

	Complex ans;
	ans = Conjugate(C);

	float divisor = pow(C.getr(), 2) + pow(C.geti(), 2);
	ans.setr(ans.getr() / divisor);
	ans.seti(ans.geti() / divisor);

	return ans;
}




void DisplayResult(Complex& result) {

	cout << endl << char(26) << " Answer is:\t";
	result.print();
}

void input(char& c, int& size) {

	do
	{
		cin >> c;
	} while ((c - 'a') < 0 or (c - 'a') > size - 1);
}

void main1(Complex* Cnums, int size) {

	char ch1, ch3, ch2;
	cout << "\nChoose number1: ";
	input(ch1, size);
	cout << "Choose number2: ";
	input(ch2, size);
	cout << "Keep result in: ";
	input(ch3, size);
	Cnums[ch3 - 'a'] = Add(Cnums[ch1 - 'a'], Cnums[ch2 - 'a']);

	DisplayResult(Cnums[ch3 - 'a']);
}

void main2(Complex* Cnums, int size) {

	char ch1, ch3, ch2;
	cout << "\nChoose number1: ";
	input(ch1, size);
	cout << "Choose number2: ";
	input(ch2, size);
	cout << "Keep result in: ";
	input(ch3, size);
	Cnums[ch3 - 'a'] = Subtract(Cnums[ch1 - 'a'], Cnums[ch2 - 'a']);

	DisplayResult(Cnums[ch3 - 'a']);
}

void main3(Complex* Cnums, int size) {

	char ch1, ch3, ch2;
	cout << "\nChoose number1: ";
	input(ch1, size);
	cout << "Choose number2: ";
	input(ch2, size);
	cout << "Keep result in: ";
	input(ch3, size);
	Cnums[ch3 - 'a'] = Multiply(Cnums[ch1 - 'a'], Cnums[ch2 - 'a']);

	DisplayResult(Cnums[ch3 - 'a']);
}

void main4(Complex* Cnums, int size) {

	char ch1, ch3, ch2;
	cout << "\nChoose number1: ";
	input(ch1, size);
	cout << "Choose number2: ";
	input(ch2, size);
	cout << "Keep result in: ";
	input(ch3, size);
	Cnums[ch3 - 'a'] = Divide(Cnums[ch1 - 'a'], Cnums[ch2 - 'a']);

	DisplayResult(Cnums[ch3 - 'a']);
}

void main5(Complex* Cnums, int size) {

	char ch1, ch3;
	cout << "\nChoose the number: ";
	input(ch1, size);
	cout << "Keep result in: ";
	input(ch3, size);
	Cnums[ch3 - 'a'] = Conjugate(Cnums[ch1 - 'a']);

	DisplayResult(Cnums[ch3 - 'a']);
}

void main6(Complex* Cnums, int size) {

	char ch1, ch3;
	cout << "\nChoose the number: ";
	input(ch1, size);
	cout << "Keep result in: ";
	input(ch3, size);

	float ans = Modulus(Cnums[ch1 - 'a']);

	Cnums[ch3 - 'a'].setr(ans), Cnums[ch3 - 'a'].seti(0);
	cout << char(26) << " Answer is:\t" << ans;
}

void main7(Complex* Cnums, int size) {

	char ch1, ch3;
	cout << "\nChoose the number: ";
	input(ch1, size);
	cout << "Keep result in: ";
	input(ch3, size);
	Cnums[ch3 - 'a'] = AddInverse(Cnums[ch1 - 'a']);

	DisplayResult(Cnums[ch3 - 'a']);
}

void main8(Complex* Cnums, int size) {

	char ch1, ch3;
	cout << "\nChoose the number: ";
	input(ch1, size);
	cout << "Keep result in: ";
	input(ch3, size);
	Cnums[ch3 - 'a'] = MulInverse(Cnums[ch1 - 'a']);

	DisplayResult(Cnums[ch3 - 'a']);
}








int main() {

	Complex* Cnums = nullptr, result = {};
	float ans = 0;
	bool main_6 = false;
	int size = 0, op;
	char cont = 'y';

	Load(Cnums, size);

	result.print();
	do
	{
		system("cls");
		cout << char(26) << " We have Complex numbers:-\n\n";
		DisplayCnums(Cnums, size);

		cout << "\n\n";
		Options_List();
		cin >> op;

		switch (op)
		{
		case 1:
			main1(Cnums, size);
			break;

		case 2:
			main2(Cnums, size);
			break;

		case 3:
			main3(Cnums, size);
			break;

		case 4:
			main4(Cnums, size);
			break;

		case 5:
			main5(Cnums, size);
			break;

		case 6:
			main6(Cnums, size);
			break;

		case 7:
			main7(Cnums, size);
			break;

		case 8:
			main8(Cnums, size);
			break;

		default:
			cout << "Wrong Input!!!";
		}


		cout << "\n\nDo you want to continue? (y/n) ";
		cin >> cont;

	} while (cont != 'n');



	return 0;
}