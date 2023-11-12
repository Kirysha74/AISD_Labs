#pragma once 
#include <iostream>
#include <complex>

using namespace std;

namespace vector {

	template <typename T>
	class Vector {
	private:
		int _size;
		T* _vector;
		inline static const double EPSILION = 0.0001;

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
			if (i < 0 || i >= _size) {
				throw exception("Incorrect index");
			}
			return _vector[i];
		}

		bool operator==(const Vector<T> rhs) {
			if (_size != rhs.get_size()) {
				throw exception("Two vectors of different sizes were transmitted");
			}
			for (int i = 0; i < _size; i++) {
				if (abs(_vector[i] - rhs[i]) > EPSILION) {
					return false;
				}
			}
			return true;
		}

		Vector() : _size(0), _vector(nullptr) {};

		~Vector() {
			delete [] _vector;
			_vector = nullptr;
			_size = 0;
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
			if (_size != rhs.get_size()) {
				throw exception("Two vectors of different sizes were transmitted");
			}
			for (int i = 0; i < _size; i++) {
				_vector[i] += rhs[i];
			}
			return *this;
		}

		Vector<T> operator+(Vector<T> rhs) const {
			if (_size != rhs.get_size()) {
				throw exception("Two vectors of different sizes were transmitted");
			}
			return rhs += *this;
		}

		Vector<T>& operator-=(const Vector<T>& rhs) {
			if (_size != rhs.get_size()) {
				throw exception("Two vectors of different sizes were transmitted");
			}
			for (int i = 0; i < _size; i++) {
				_vector[i] -= rhs[i];
			}
			return *this;
		}

		Vector<T> operator-(Vector rhs) const {
			Vector<T> a(*this);
			if (_size != rhs.get_size()) {
				throw exception("Two vectors of different sizes were transmitted");
			}
			return a -= rhs;
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
			if (_size != rhs.get_size()) {
				throw exception("Two vectors of different sizes were transmitted");
			}
			T k = 0;
			for (int i = 0; i < _size; i++) {
				k += _vector[i] * rhs[i];
			}
			return k;
		}

		Vector<T>& operator/=(const T a) {
			try {
				if (a == 0) {
					throw exception("Division by zero");
				}
			}
			catch(exception) {
				return *this;
			}
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
	Vector<complex<float>>::Vector(int size, int up, int down) : _size(size), _vector(new complex<float>[_size]) {
		for (int i = 0; i < _size; i++) {
			_vector[i] = complex<float>(rand() % (up - down) + down + 0.00001 * rand(), rand() % (up - down) + down + 0.00001 * rand());
		}
	}

	template<>
	complex<float> Vector<complex<float>>::operator*(const Vector<complex<float>>& rhs) {
		if (_size != rhs.get_size()) {
			throw exception("Two vectors of different sizes were transmitted");
		}
		complex<float> k = 0;
		for (int i = 0; i < _size; i++) {
			k += _vector[i] * conj(rhs[i]);
		}
		return k;
	}

	template<>
	Vector<complex<double>>::Vector(int size, int up, int down) : _size(size), _vector(new complex<double>[_size]) {
		for (int i = 0; i < _size; i++) {
			_vector[i] = complex<double>(rand() % (up - down) + down + 0.00001 * rand(), rand() % (up - down) + down + 0.00001 * rand());
		}
	}

	template<>
	complex<double> Vector<complex<double>>::operator*(const Vector<complex<double>>& rhs) {
		if (_size != rhs.get_size()) {
			throw exception("Two vectors of different sizes were transmitted");
		}
		complex<double> k = 0;
		for (int i = 0; i < _size; i++) {
			k += _vector[i] * conj(rhs[i]);
		}
		return k;
	}

	template<>
	Vector<complex<float>>& Vector<complex<float>>::operator/=(const complex<float> a) {
		try {
			if (a.imag() == 0 && a.real() == 0) {
				throw invalid_argument("Division by zero");
			}
		}
		catch (invalid_argument) {
			cout << "DIVISION BY ZERO";
			return *this;
		}
		for (int i = 0; i < _size; i++) {
			_vector[i] /= a;
		}
		return *this;
	}

	template<>
	Vector<complex<double>>& Vector<complex<double>>::operator/=(const complex<double> a) {
		try {
			if (a.imag() == 0 && a.real() == 0) {
				throw exception("Division by zero");
			}
		}
		catch (exception) {
			return *this;
		}
		for (int i = 0; i < _size; i++) {
			_vector[i] /= a;
		}
		return *this;
	}

	template<>
	bool Vector<complex<float>>::operator==(const Vector<complex<float>> rhs) {
		if (_size != rhs.get_size()) {
			throw exception("Two vectors of different sizes were transmitted");
		}
		for (int i = 0; i < _size; i++) {
			if (abs(_vector[i].imag() - rhs[i].imag()) > EPSILION || abs(_vector[i].real() - rhs[i].real()) > EPSILION) {
				return false;
			}
		}
		return true;
	}

	template<>
	bool Vector<complex<double>>::operator==(const Vector <complex<double>> rhs) {
		if (_size != rhs.get_size()) {

			throw exception("Two vectors of different sizes were transmitted");
		}
		for (int i = 0; i < _size; i++) {
			if ((abs(_vector[i].imag() - rhs[i].imag()) > EPSILION) || (abs(_vector[i].real() - rhs[i].real()) > EPSILION)) {
				return false;
			}
		}
		return true;
	}

	template <typename T>
	Vector<T> operator*(T lhs, const Vector<T> rhs) {
		return rhs * lhs;
	}

	template<typename T>
	std::ostream& operator<<(std::ostream& stream, const Vector<T>& a) {
		for (int i = 0; i < a.get_size(); i++) {
			stream << a[i] << " ";
		}
		return stream;
	}

	template <typename T>
	Vector<T> bisector(Vector<T> lhs, Vector<T> rhs) {
		return ((lhs + rhs) / 2);
	}
}