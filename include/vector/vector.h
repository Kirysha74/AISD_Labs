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

	void print() const {
		for (int i = 0; i < _size; i++) {
			cout << _vector[i] << endl;
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

template <typename T>
Vector<T> operator*(T rhs, const Vector<T> lhs) {
	return lhs * rhs;
}

template <typename T>
Vector<T> bes(Vector<T> lhs, Vector<T> rhs) {
	return ((lhs + rhs) / 2);
}