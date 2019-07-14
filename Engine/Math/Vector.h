#pragma once

#include <cmath>
#include <windows.h>
#include <cassert>

class Vector
{
	// Constructors
	Vector()
	{
		RtlZeroMemory(&m_val, MEM_SIZE);
	}

	Vector(const Vector& other)
	{
		RtlCopyMemory(&m_val, &other.m_val, MEM_SIZE);
	}

	Vector(float x, float y, float z, float w)
	{
		m_val[0] = x;
		m_val[1] = y;
		m_val[2] = z;
		m_val[3] = w;
	}

	// Accessors
	const float& X() const { return m_val[0]; }
	const float& Y() const { return m_val[1]; }
	const float& Z() const { return m_val[2]; }
	const float& W() const { return m_val[3]; }

	// Unary operators
	inline const Vector& operator+() const { return *this; }
	inline Vector operator-() const { return Vector(-m_val[0], -m_val[1], -m_val[2], -m_val[3]); }
	inline float operator[](int i) const { return m_val[i]; }
	inline float& operator[](int i) { return m_val[i]; }

	// Binary Operators
	inline Vector& operator+=(const Vector& other);
	inline Vector& operator-=(const Vector& other);
	inline Vector& operator*=(const Vector& other);
	inline Vector& operator/=(const Vector& other);
	inline Vector& operator+=(float other);
	inline Vector& operator-=(float other);
	inline Vector& operator*=(float other);
	inline Vector& operator/=(float other);

	// Helper Functions
	inline float length() const
	{
		return sqrt(squared_length());
	}

	inline float squared_length() const
	{
		assert(!(m_val[0] == 0 && m_val[1] == 0 && m_val[2] == 0 && m_val[3] == 0));
		return (m_val[0] * m_val[0] + m_val[1] * m_val[1] + m_val[2] * m_val[2] + m_val[3] * m_val[3]);
	}

	inline void make_unit_vector();

private:
	float m_val[4];

	static constexpr size_t MEM_SIZE = 4 * sizeof(float);
};


inline Vector& Vector::operator+=(const Vector& other)
{
	m_val[0] += other.m_val[0];
	m_val[1] += other.m_val[1];
	m_val[2] += other.m_val[2];
	m_val[3] += other.m_val[3];
	return *this;
}

inline Vector& Vector::operator-=(const Vector& other)
{
	m_val[0] -= other.m_val[0];
	m_val[1] -= other.m_val[1];
	m_val[2] -= other.m_val[2];
	m_val[3] -= other.m_val[3];
	return *this;
}

inline Vector& Vector::operator*=(const Vector& other)
{
	m_val[0] *= other.m_val[0];
	m_val[1] *= other.m_val[1];
	m_val[2] *= other.m_val[2];
	m_val[3] *= other.m_val[3];
	return *this;
}

inline Vector& Vector::operator/=(const Vector& other)
{
	m_val[0] /= other.m_val[0];
	m_val[1] /= other.m_val[1];
	m_val[2] /= other.m_val[2];
	m_val[3] /= other.m_val[3];
	return *this;
}

inline Vector& Vector::operator+=(const float other)
{
	m_val[0] += other;
	m_val[1] += other;
	m_val[2] += other;
	m_val[3] += other;
	return *this;
}

inline Vector& Vector::operator-=(const float other)
{
	m_val[0] -= other;
	m_val[1] -= other;
	m_val[2] -= other;
	m_val[3] -= other;
	return *this;
}

inline Vector& Vector::operator*=(const float other)
{
	m_val[0] *= other;
	m_val[1] *= other;
	m_val[2] *= other;
	m_val[3] *= other;
	return *this;
}

inline Vector& Vector::operator/=(const float other)
{
	m_val[0] /= other;
	m_val[1] /= other;
	m_val[2] /= other;
	m_val[3] /= other;
	return *this;
}

inline void Vector::make_unit_vector()
{
	assert(!(m_val[0] == 0 && m_val[1] == 0 && m_val[2] == 0));
	float k = 1.0f / squared_length();
	m_val[0] *= k;
	m_val[1] *= k;
	m_val[2] *= k;
}
