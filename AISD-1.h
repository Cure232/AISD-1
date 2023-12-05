// AISD-1.h : включаемый файл для стандартных системных включаемых файлов
// или включаемые файлы для конкретного проекта.

#pragma once

#include <iostream>
#include <stdexcept>
#include <random>
#include <complex>



template <typename T>
class Vector {
	int _dimension;
	T* _values;
public:
	int getDimension() {
		return _dimension;
	}

	int vectorModule() {
		T sum;
		for (int i = 0; i < _dimension; i++) {
			T x = _values[i];
			sum += x * x;
		}
		return sqrt(sum);
	}

	Vector(int dimension) {
		_dimension = dimension;
		_values = new T[dimension];
		for (int i = 0; i < dimension; i++) {
			_values[i] = 0;
		}
	}

	Vector(int dimension, T values[]) {
		_dimension = dimension;
		_values = new T[dimension];
		for (int i = 0; i < dimension; i++) {
			_values[i] = values[i];
		}
	}
	Vector(int dimension, double minValue, double maxValue) { 
		random_device rd;
		mt19937 e{ rd() }; // or std::default_random_engine e{rd()};
		uniform_real_distribution<double> dist{ minValue, maxValue };

		_dimension = dimension;
		_values = new T[dimension];
		for (int i = 0; i < dimension; i++) {
			_values[i] = dist(e);
		}
	}
	
	~Vector() {
		delete(_values);
	}

	T& operator[](int i) {
		return _values[i];
	}
	const T& operator[](int i) const {
		return _values[i];
	}

	Vector operator+(const Vector& rhs) const {
		if (_dimension == rhs._dimension)
		{
			Vector v(_dimension);
			for (int i = 0; i < _dimension; i++) {
				v[i] = _values[i] + rhs[i];
			}
			return v;
		}
		else
		{
			throw invalid_argument("Vectors have diffrent dimensions");
		}
	}
	Vector operator-(const Vector& rhs) const {
		if (_dimension == rhs._dimension)
		{
			Vector v(_dimension);
			for (int i = 0; i < _dimension; i++) {
				v[i] = _values[i] - rhs[i];
			}
			return v;
		}
		else
		{
			throw invalid_argument("Vectors have diffrent dimensions");
		}
	}
	T operator*(const Vector& rhs) const {
		if (_dimension == rhs._dimension)
		{
			T sum;
			for (int i = 0; i < _dimension; i++) {
				sum += _values[i] * rhs[i];
			}
			return sum;
		}
		else
		{
			throw invalid_argument("Vectors have diffrent dimensions");
		}
	}
	Vector operator/(const Vector& rhs) const {

	}

	Vector operator+(const T& rhs) const {

	}
	Vector operator-(const T& rhs) const {

	}
	Vector operator*(const T& rhs) const {

	}
	Vector operator/(const T& rhs) const {

	}
};

// TODO: установите здесь ссылки на дополнительные заголовки, требующиеся для программы.
