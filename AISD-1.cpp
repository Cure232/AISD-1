// AISD-1.cpp: определяет точку входа для приложения.
//

#include "AISD-1.h"

using namespace std;


int main()
{
	cout << "Hello CMake." << endl;
	int vals[3];
	vals[0] = 1;
	vals[1] = 2;
	vals[2] = 3;
	Vector<int> v = Vector<int>(3, vals);
	cout << v[0] << " " << v[1] << " " << v[2] << endl;
	return 0;
}
