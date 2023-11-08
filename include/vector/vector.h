#pragma once
#include <iostream>
#include <complex>

using namespace std;

template <typename T>
class Vector {
private:
	int _size;
	T* _vector;
public:

	int get_size() const {
		return _size;
	}

	Vector<T>& operator=(const Vector<T>& rhs) {
		_size = rhs.get_size();
		_vector = new T[_size];
		for (int i = 0; i < _size; i++) {
			_vector[i] = rhs[i];
		}
	}

	T& operator[](int i) const {
		return _vector[i];
	}

	Vector() : _size(2), _vector(new T[_size]) {
		for (int i = 0; i < _size; i++) {
			_vector[i] = rand() + 0.000001 * rand();
		}
	}

	Vector(int size, T value) : _size(size), _vector(new T[_size]) {
		for (int i = 0; i < _size; i++) {
			_vector[i] = value;
		}
	}

	Vector(int size, T* value) : _size(size), _vector(new T[_size]) {
		for (int i = 0; i < _size; i++) {
			_vector[i] = value[i];
		}
	}

	Vector(const Vector<T>& vec) : _size(vec.get_size()), _vector(new T[_size]) {
		for (int i = 0; i < _size; i++) {
			_vector[i] = vec[i];
		}
	}

	Vector(int size, int up, int down) : _size(size), _vector(new T[_size]) {
		for (int i = 0; i < _size; i++) {
			_vector[i] = rand() % (up - down) + down + 0.00001 * rand();
		}
	}

	Vector<T>& operator+=(const Vector<T>& rhs) {
		for (int i = 0; i < _size; i++) {
			_vector[i] += rhs[i];
		}
		return *this;
	}

	Vector<T> operator+(Vector<T> rhs) const {
		return rhs += *this;
	}

	Vector<T>& operator-=(const Vector<T>& rhs) {
		for (int i = 0; i < _size; i++) {
			_vector[i] -= rhs[i];
		}
		return *this;
	}

	Vector<T> operator-(Vector rhs) const {
		return rhs -= *this;
	}

	Vector<T>& operator*=(const T a) {
		for (int i = 0; i < _size; i++) {
			_vector[i] *= a;
		}
		return *this;
	}

	Vector<T> operator*(T rhs) const {
		Vector<T> b(*this);
		return b *= rhs;
	}

	T operator*(const Vector<T>& rhs) {
		T k = 0;
		for (int i = 0; i < _size; i++) {
			k += _vector[i] * rhs[i];
		}
		return k;
	}

	Vector<T>& operator/=(const T a) {
		for (int i = 0; i < _size; i++) {
			_vector[i] /= a;
		}
		return *this;
	}

	Vector<T> operator/(T rhs) const {
		Vector<T> b(*this);
		return b /= rhs;
	}
};

template<>
Vector<complex<float>>::Vector() : _size(2), _vector(new complex<float>[_size]) {
	for (int i = 0; i < _size; i++) {
		_vector[i] = complex<float>(rand() + 0.00001 * rand(), rand() + 0.00001 * rand());
	}
}

template<>
Vector<complex<float>>::Vector(int size, int up, int down) : _size(size), _vector(new complex<float>[_size]) {
	for (int i = 0; i < _size; i++) {
		_vector[i] = complex<float>(rand() % (up - down) + down + 0.00001 * rand(), rand() % (up - down) + down + 0.00001 * rand());
	}
}

template<>
complex<float> Vector<complex<float>>::operator*(const Vector<complex<float>>& rhs) {
	complex<float> k = 0;
	for (int i = 0; i < _size; i++) {
		k += _vector[i] * conj(rhs[i]);
	}
	return k;
}

template<>
Vector<complex<double>>::Vector() : _size(2), _vector(new complex<double>[_size]) {
	for (int i = 0; i < _size; i++) {
		_vector[i] = complex<double>(rand() + 0.00001 * rand(), rand() + 0.00001 * rand());
	}
}

template<>
Vector<complex<double>>::Vector(int size, int up, int down) : _size(size), _vector(new complex<double>[_size]) {
	for (int i = 0; i < _size; i++) {
		_vector[i] = complex<double>(rand() % (up - down) + down + 0.00001 * rand(), rand() % (up - down) + down + 0.00001 * rand());
	}
}

template<>
complex<double> Vector<complex<double>>::operator*(const Vector<complex<double>>& rhs) {
	complex<double> k = 0;
	for (int i = 0; i < _size; i++) {
		k += _vector[i] * conj(rhs[i]);
	}
	return k;
}

template <typename T>
Vector<T> operator*(T rhs, const Vector<T> lhs) {
	return lhs * rhs;
}

template <typename T>
Vector<T> bes(Vector<T> lhs, Vector<T> rhs) {
	return ((lhs + rhs) / 2);
}

template<typename T>
std::ostream& operator << (std::ostream& stream, const Vector<T>& a) {
	for (int i = 0; i < _size; i++) {
		cout << _vector[i] << endl;
	}
	return stream;
}

