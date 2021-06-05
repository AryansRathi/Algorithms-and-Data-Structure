/*
CH-231-A
a1 p1.[c or cpp or h]
Aryans Rathi
arathi@jacobs-university.de
*/
#include <iostream>
using namespace std;

template <typename T>
int array(T arr[], int size, T search)
{
	for (int i = 0; i < size; i++)
	{
		if (search == arr[i])
		{
			return i;
		}
	}
	return -1;
}

class Complex
{
private:
	double real, img;

public:
	Complex(double real, double img)
	{
		this->real = real;
		this->img = img;
	}
	bool operator==(const Complex &a)
	{
		if ((this->real == a.real) && (this->img == a.img))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
	friend ostream &operator<<(ostream &out, const Complex &a)
	{
		out << a.real << "+" << a.img << "i" << endl;
		return out;
	}
	Complex operator+(const Complex a)
	{
		return Complex(this->real + a.real, this->img + a.img);
	}
};

int main()
{
	int a[] = {1, 2, 3, 4};
	cout << "The position is" << endl;
	cout << array(a, 4, 2) << endl;

	double d[] = {1.12, 2.21, 3.33, 4.46, 5.52, 6.61};
	cout << "The position is" << endl;
	cout << array(d, 6, 3.0) << endl;

	string s[] = {"apple", "cherry", "orange"};
	cout << "The position is" << endl;
	cout << array(s, 3, string("orange")) << endl;

	Complex c[] = {Complex(3, 4), Complex(1, 2), Complex(-6, -7)};
	cout << "The position is:" << endl;
	cout << array(c, 3, Complex(-6, -7)) << endl;
	return 0;
}