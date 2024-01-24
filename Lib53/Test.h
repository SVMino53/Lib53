#pragma once



namespace Test
{
	// TODO: Add constraints; limit 'T' to be int, float or double.
	template <typename T = double>
	struct Vector2
	{
		T x, y;

		Vector2();
		Vector2(T x, T y);

		Vector2 operator+(const Vector2& other) const;
		Vector2 operator-(const Vector2& other) const;
		template <typename U>
		Vector2 operator*(const U& other) const;
		template <typename U>
		Vector2 operator/(const U& other) const;

		Vector2& operator=(const Vector2& other);
		Vector2& operator+=(const Vector2& other);
		Vector2& operator-=(const Vector2& other);
		template <typename U>
		Vector2& operator*=(const U& other);
		template <typename U>
		Vector2& operator/=(const U& other);

		bool operator==(const Vector2& other) const;
		bool operator!=(const Vector2& other) const;
	};
}