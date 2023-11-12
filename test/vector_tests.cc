#include <vector/vector.h>
#include <complex>

using namespace vector;


int main() {

	float val_a[2] = { 1.9, 2.8 }, val_b[2] = { 3.4, 5.7 };
	Vector<float> a(2, val_a), b(2, val_b);
	cout << "Vector a: {" << a << "}" << "Vector b: {" << b << "}" << endl;
	cout << "Bisector - " << bisector(a, b) << endl;
	cout << "Sum " << a + b << endl;
	cout << "Difference " << a - b << endl;
	cout << "Multiplication of vectors " << a * b << endl;
	cout << "Division " << a / 0 << endl;
	cout << "Multiplication by scalar " << a * 2 << endl;
	cout << "Multiplication by scalar " << (float)2 * a << endl;

	complex<float> val_c[2] = { complex<float>(1.3, 5.6), complex<float>(4.9, 7.4) }, val_d[2] = { complex<float>(3.2, 2.8), complex<float>(6.7, 2.4) };
	Vector<complex<float>> c(2, val_c), d(2, val_d);
	cout << "Vector c: {" << c << "}" << "Vector d: {" << d << "}" << endl;
	cout << "Bisector - " << bisector(c, d) << endl;
	cout << "Sum " << c + d << endl;
	cout << "Difference " << c - d << endl;
	cout << "Multiplication of vectors " << c * d << endl;
	cout << "Division " << c / (complex<float>)(0, 0) << endl;
	cout << "Multiplication by scalar " << c * 2 << endl;
	cout << "Multiplication by scalar " << (complex<float>)(9.4, 4.3) * c << endl;

	cout << (a == a) << endl;
	cout << (a == b) << endl;

	cout << (c == c) << endl;
	cout << (c == d) << endl;

	return 0;
}