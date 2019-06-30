#pragma once

template <typename T> class Vector2D
{
public:
	// Core values
	T x;
	T y;

	// Constuctors
	Vector2D();
	Vector2D(const T& xVal, const T& yVal);

	// Allow to set sign in front of vector as you please
	const Vector2D& operator+() const;
	Vector2D operator-() const;

	// Operations between two vectors
	template<typename S> Vector2D operator+(const Vector2D<S>& other) const;
	template<typename S> Vector2D operator-(const Vector2D<S>& other) const;
	template<typename S> Vector2D operator*(const Vector2D<S>& other) const;
	template<typename S> Vector2D& operator=(const Vector2D<S>& other);

	// Operations between vector and scalar
	Vector2D operator*(T s) const;
	Vector2D operator/(T s) const;




	double length() const;
};

#ifndef _VECTOR_2D_IMPL
#include "Vector2D.cpp"
#endif
