#include "Test.h"
#include <iostream>



namespace Test
{
	template <typename T>
	Vector2<T>::Vector2()
	{
		x = (T)0;
		y = (T)0;
	};

	template <typename T>
	Vector2<T>::Vector2(T x, T y)
	{
		this->x = x;
		this->y = y;
	};

	template <typename T>
	Vector2<T> Vector2<T>::operator+(const Vector2& other) const
	{

	}

	template <typename T>
	Vector2<T> Vector2<T>::operator-(const Vector2& other) const
	{

	}

	template <typename T>
	template <typename U>
	Vector2<T> Vector2<T>::operator*(const U& other) const
	{

	}

	template <typename T>
	template <typename U>
	Vector2<T> Vector2<T>::operator/(const U& other) const
	{

	}


	template <typename T>
	Vector2<T>& Vector2<T>::operator=(const Vector2& other)
	{

	}

	template <typename T>
	Vector2<T>& Vector2<T>::operator+=(const Vector2& other)
	{

	}

	template <typename T>
	Vector2<T>& Vector2<T>::operator-=(const Vector2& other)
	{

	}

	template <typename T>
	template <typename U>
	Vector2<T>& Vector2<T>::operator*=(const U& other)
	{

	}

	template <typename T>
	template <typename U>
	Vector2<T>& Vector2<T>::operator/=(const U& other)
	{

	}


	template <typename T>
	bool Vector2<T>::operator==(const Vector2& other) const
	{

	}

	template <typename T>
	bool Vector2<T>::operator!=(const Vector2& other) const
	{

	}
}