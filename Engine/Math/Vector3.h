#pragma once

#include "Vector.h"

namespace ArchEngine
{
	class Vector;

	class Vector3 : public Vector
	{

	public:
		Vector3() : Vector() {}

		// Constructor - Destructor
		Vector3(float x, float y, float z):
			Vector(x, y, z, 0)
		{
		}

		virtual ~Vector3()
		{
		}

		// Unary operators
		inline const Vector3& operator+() const { return *this; }
		inline Vector3 operator-() const { return Vector3(-X(), -Y(), -Z()); }

		// Binary Operators
		inline Vector3& operator+=(const Vector3& other);
		inline Vector3& operator-=(const Vector3& other);
		inline Vector3& operator*=(const Vector3& other);
		inline Vector3& operator/=(const Vector3& other);
		inline Vector3& operator+=(float other);
		inline Vector3& operator-=(float other);
		inline Vector3& operator*=(float other);
		inline Vector3& operator/=(float other);
	};
}

// Stream Helpers
inline std::istream& operator>>(std::istream& istream, ArchEngine::Vector3& val)
{
	istream >> val[0] >> val[1] >> val[2];
	return istream;
}

inline std::ostream& operator<<(std::ostream& ostream, const ArchEngine::Vector3& val)
{
	ostream << "x : " << val.X() << ", y : "<< val.Y() << ". z : "<< val.Z();
	return ostream;
}

// Operator Overloads

inline ArchEngine::Vector3& ArchEngine::Vector3::operator+=(const ArchEngine::Vector3& other)
{
	m_val[0] += other.m_val[0];
	m_val[1] += other.m_val[1];
	m_val[2] += other.m_val[2];
	return *this;
}

inline ArchEngine::Vector3& ArchEngine::Vector3::operator-=(const ArchEngine::Vector3& other)
{
	m_val[0] -= other.m_val[0];
	m_val[1] -= other.m_val[1];
	m_val[2] -= other.m_val[2];
	return *this;
}

inline ArchEngine::Vector3& ArchEngine::Vector3::operator*=(const ArchEngine::Vector3& other)
{
	m_val[0] *= other.m_val[0];
	m_val[1] *= other.m_val[1];
	m_val[2] *= other.m_val[2];
	return *this;
}

inline ArchEngine::Vector3& ArchEngine::Vector3::operator/=(const ArchEngine::Vector3& other)
{
	m_val[0] /= other.m_val[0];
	m_val[1] /= other.m_val[1];
	m_val[2] /= other.m_val[2];
	return *this;
}

inline ArchEngine::Vector3& ArchEngine::Vector3::operator+=(const float other)
{
	m_val[0] += other;
	m_val[1] += other;
	m_val[2] += other;
	return *this;
}

inline ArchEngine::Vector3& ArchEngine::Vector3::operator-=(const float other)
{
	m_val[0] -= other;
	m_val[1] -= other;
	m_val[2] -= other;
	return *this;
}

inline ArchEngine::Vector3& ArchEngine::Vector3::operator*=(const float other)
{
	m_val[0] *= other;
	m_val[1] *= other;
	m_val[2] *= other;
	return *this;
}

inline ArchEngine::Vector3& ArchEngine::Vector3::operator/=(const float other)
{
	m_val[0] /= other;
	m_val[1] /= other;
	m_val[2] /= other;
	return *this;
}

// Math Helpers
inline ArchEngine::Vector3 operator+(const ArchEngine::Vector3& v1, const ArchEngine::Vector3& v2)
{
	return ArchEngine::Vector3(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2]);
}

inline ArchEngine::Vector3 operator-(const ArchEngine::Vector3& v1, const ArchEngine::Vector3& v2)
{
	return ArchEngine::Vector3(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2]);
}

inline ArchEngine::Vector3 operator*(const ArchEngine::Vector3& v1, const ArchEngine::Vector3& v2)
{
	return ArchEngine::Vector3(v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2]);
}

inline ArchEngine::Vector3 operator/(const ArchEngine::Vector3& v1, const ArchEngine::Vector3& v2)
{
	return ArchEngine::Vector3(v1[0] / v2[0], v1[1] / v2[1], v1[2] / v2[2]);
}

inline ArchEngine::Vector3 operator+(const ArchEngine::Vector3& v, float val)
{
	return ArchEngine::Vector3(v[0] + val, v[1] + val, v[2] + val);
}

inline ArchEngine::Vector3 operator-(const ArchEngine::Vector3& v, float val)
{
	return ArchEngine::Vector3(v[0] - val, v[1] - val, v[2] - val);
}

inline ArchEngine::Vector3 operator*(const ArchEngine::Vector3& v, float val)
{
	return ArchEngine::Vector3(v[0] * val, v[1] * val, v[2] * val);
}

inline ArchEngine::Vector3 operator/(const ArchEngine::Vector3& v, float val)
{
	return ArchEngine::Vector3(v[0] / val, v[1] / val, v[2] / val);
}

inline ArchEngine::Vector3 operator*(float val, const ArchEngine::Vector3& v)
{
	return ArchEngine::Vector3(val * v[0], val * v[1], val * v[2]);
}


inline float dot(const ArchEngine::Vector3& v1, const ArchEngine::Vector3& v2)
{
	return v1[0] * v2[0] + v1[1] * v2[1] + v1[2] * v2[2];
}

inline ArchEngine::Vector3 cross(const ArchEngine::Vector3& v1, const ArchEngine::Vector3& v2)
{
	return ArchEngine::Vector3(
		v1[1] * v2[2] - v1[2] * v2[1],
		-(v1[0] * v2[2] - v1[2] * v2[0]),
		v1[0] * v2[1] - v1[1] * v2[0]
	);
}

inline ArchEngine::Vector3 unit_vector(const ArchEngine::Vector3& v)
{
	return v / v.length();
}
