#define _VECTOR_2D_IMPL

#include "Vector2D.h"
#include <math.h>



// + sign in front of vector 
template<typename T> const Vector2D<T>& Vector2D<T>::operator+() const
{
	return *this;
}

// - sign in front of vector
template<typename T> Vector2D<T> Vector2D<T>::operator-() const
{
	return Vector2D(-x, -y);
}

// Empty constructor
template<typename T> Vector2D<T>::Vector2D()
	: x(0), y(0)
{
}

// Initialize 2D vector
template<typename T> Vector2D<T>::Vector2D(const T& xVal, const T& yVal)
	: x(xVal), y(yVal)
{
}

// Addition of a vector
template<typename T> template<typename S> Vector2D<T> Vector2D<T>::operator+(const Vector2D<S>& other) const
{
	return Vector2D<T>(x + other.x, y + other.y);
}

// Subtraction of a vector
template<typename T> template<typename S> Vector2D<T> Vector2D<T>::operator-(const Vector2D<S>& other) const
{
	return Vector2D<T>(x - other.x, y - other.y);
}

// Elementwise multiplication of a vector
template<typename T> template<typename S> Vector2D<T> Vector2D<T>::operator*(const Vector2D<S>& other) const
{
	return Vector2D<T>(x * other.x, y * other.y);
}

// Calculate the length of the vector
template<typename T> double Vector2D<T>::Length() const
{
	return sqrt(x * x + y * y);
}


