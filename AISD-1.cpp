// AISD-1.cpp: определяет точку входа для приложения.
//

#include "AISD-1.h"

using namespace std;


complex<float> Vector<complex<float>>::operator*(const Vector<complex<float>>& rhs) const {
	if (_dimension == rhs._dimension)
	{
		complex<float> sum(0.0, 0.0);
		for (int i = 0; i < _dimension; i++) {
			complex<float> z1 = _values[i];
			complex<float> z2 = rhs[i];
			complex<float> altered_z2(z2.real(), -1 * z2.imag());
			sum += (z1 * altered_z2);
		}
		return sum;
	}
	else
	{
		throw invalid_argument("Vectors have diffrent dimensions");
	}
};

complex<double> Vector<complex<double>>::operator*(const Vector<complex<double>>& rhs) const {
	if (_dimension == rhs._dimension)
	{
		complex<float> sum(0.0, 0.0);
		for (int i = 0; i < _dimension; i++) {
			complex<double> z1 = _values[i];
			complex<double> z2 = rhs[i];
			complex<double> altered_z2(z2.real(), -1 * z2.imag());
			sum += (z1 * altered_z2);
		}
		return sum;
	}
	else
	{
		throw invalid_argument("Vectors have diffrent dimensions");
	}
};

template<typename T>
Vector<T> operator*(const Vector<T>& rhs) {
	Vector v = Vector(rhs);
	T lhs = *this;
	for (int i = 0; i < _dimension; i++) {
		v._values[i] *= lhs;
	}
	return v;
}

template<typename T>
ostream& operator<<(ostream& os, const Vector<T>& v) {
	os << "( ";
	int dimension = v.getDimension();
	for (int i = 0; i < dimension; i++) {
		os << v[0] << "; ";
	}
	return os << ")";
}

double radiansToDegrees(double x) {
	return x / (3.14 / 180);
}


int main()
{
	cout << "My tests" << endl;
	cout << "Vector scalar multiplication:" << endl;
	complex<double> c1[3];
	c1[0] = complex<double>(1.0, -3.0);
	c1[1] = complex<double>(1.0, -1.0);
	c1[2] = complex<double>(1.0, -3.0);
	Vector<complex<double>> v1 = Vector<complex<double>>(3, c1);

	complex<double> c2[3];
	c2[0] = complex<double>(2.0, -2.0);
	c2[1] = complex<double>(2.0, -2.0);
	c2[2] = complex<double>(2.0, -2.0);
	Vector<complex<double>> v2 = Vector<complex<double>>(3, c2);
	 
	complex<double> ans = (v1 * v2);
	cout << v1 << endl;
	cout << v2 << endl;
	cout << ans << endl << endl;

	cout << "Vector and scalar multiplication:" << endl;
	Vector<int> v(3, -10, 10);
	cout << v << endl;
	v = 2 * v;
	cout << v << endl;
	v = v * 2;
	cout << v << endl;


	cout << endl << "Task 3" << endl;
	Vector<int> a(2, -10, 10);
	Vector<int> b(2, -10, 10);
	double angle1 = radiansToDegrees(acos((a * b) / (a.vectorModule() * b.vectorModule())));
	double angle2 = 180 - angle1;
	cout << a << endl << b << endl << angle1 << endl << angle2 << endl;
	return 0;
}
