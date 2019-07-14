#pragma once

#include <cmath>
#include <windows.h>
#include <cassert>
#include <istream>

namespace ArchEngine
{
	class Vector
	{

	public:
		// Constructor - Destructor
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

		virtual ~Vector()
		{
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
		inline Vector& operator+=(const Vector & other);
		inline Vector& operator-=(const Vector & other);
		inline Vector& operator*=(const Vector & other);
		inline Vector& operator/=(const Vector & other);
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

	protected:
		float m_val[4];

		static constexpr size_t MEM_SIZE = 4 * sizeof(float);
	};
}

// Operator Overloads
inline ArchEngine::Vector& ArchEngine::Vector::operator+=(const ArchEngine::Vector& other)
{
	m_val[0] += other.m_val[0];
	m_val[1] += other.m_val[1];
	m_val[2] += other.m_val[2];
	m_val[3] += other.m_val[3];
	return *this;
}

inline ArchEngine::Vector& ArchEngine::Vector::operator-=(const ArchEngine::Vector& other)
{
	m_val[0] -= other.m_val[0];
	m_val[1] -= other.m_val[1];
	m_val[2] -= other.m_val[2];
	m_val[3] -= other.m_val[3];
	return *this;
}

inline ArchEngine::Vector& ArchEngine::Vector::operator*=(const ArchEngine::Vector& other)
{
	m_val[0] *= other.m_val[0];
	m_val[1] *= other.m_val[1];
	m_val[2] *= other.m_val[2];
	m_val[3] *= other.m_val[3];
	return *this;
}

inline ArchEngine::Vector& ArchEngine::Vector::operator/=(const ArchEngine::Vector& other)
{
	m_val[0] /= other.m_val[0];
	m_val[1] /= other.m_val[1];
	m_val[2] /= other.m_val[2];
	m_val[3] /= other.m_val[3];
	return *this;
}

inline ArchEngine::Vector& ArchEngine::Vector::operator+=(const float other)
{
	m_val[0] += other;
	m_val[1] += other;
	m_val[2] += other;
	m_val[3] += other;
	return *this;
}

inline ArchEngine::Vector& ArchEngine::Vector::operator-=(const float other)
{
	m_val[0] -= other;
	m_val[1] -= other;
	m_val[2] -= other;
	m_val[3] -= other;
	return *this;
}

inline ArchEngine::Vector& ArchEngine::Vector::operator*=(const float other)
{
	m_val[0] *= other;
	m_val[1] *= other;
	m_val[2] *= other;
	m_val[3] *= other;
	return *this;
}

inline ArchEngine::Vector& ArchEngine::Vector::operator/=(const float other)
{
	m_val[0] /= other;
	m_val[1] /= other;
	m_val[2] /= other;
	m_val[3] /= other;
	return *this;
}

inline void ArchEngine::Vector::make_unit_vector()
{
	assert(!(m_val[0] == 0 && m_val[1] == 0 && m_val[2] == 0 && m_val[3] == 0));
	float k = 1.0f / squared_length();
	m_val[0] *= k;
	m_val[1] *= k;
	m_val[2] *= k;
	m_val[3] *= k;
}

// Stream Helpers
inline std::istream& operator>>(std::istream& istream, ArchEngine::Vector& val)
{
	istream >> val[0] >> val[1] >> val[2] >> val[3];
	return istream;
}

inline std::ostream& operator<<(std::ostream& ostream, const ArchEngine::Vector& val)
{
	ostream << "x : " << val.X() << ", y : " << val.Y() << ". z : " << val.Z() << ". w : " << val.W();
	return ostream;
}

// External Math Helpers
inline ArchEngine::Vector operator+(const ArchEngine::Vector& v1, const ArchEngine::Vector& v2)
{
	return ArchEngine::Vector(v1[0] + v2[0], v1[1] + v2[1], v1[2] + v2[2], v1[3] + v2[3]);
}

inline ArchEngine::Vector operator-(const ArchEngine::Vector & v1, const ArchEngine::Vector & v2)
{
	return ArchEngine::Vector(v1[0] - v2[0], v1[1] - v2[1], v1[2] - v2[2], v1[3] - v2[3]);
}

inline ArchEngine::Vector operator*(const ArchEngine::Vector & v1, const ArchEngine::Vector & v2)
{
	return ArchEngine::Vector(v1[0] * v2[0], v1[1] * v2[1], v1[2] * v2[2], v1[3] * v2[3]);
}

inline ArchEngine::Vector operator/(const ArchEngine::Vector & v1, const ArchEngine::Vector & v2)
{
	return ArchEngine::Vector(v1[0] / v2[0], v1[1] / v2[1], v1[2] / v2[2], v1[3] / v2[3]);
}

inline ArchEngine::Vector operator+(const ArchEngine::Vector & v, float val)
{
	return ArchEngine::Vector(v[0] + val, v[1] + val, v[2] + val, v[3] + val);
}

inline ArchEngine::Vector operator-(const ArchEngine::Vector & v, float val)
{
	return ArchEngine::Vector(v[0] - val, v[1] - val, v[2] - val, v[3] - val);
}

inline ArchEngine::Vector operator*(const ArchEngine::Vector & v, float val)
{
	return ArchEngine::Vector(v[0] * val, v[1] * val, v[2] * val, v[3] * val);
}

inline ArchEngine::Vector operator/(const ArchEngine::Vector & v, float val)
{
	return ArchEngine::Vector(v[0] / val, v[1] / val, v[2] / val, v[3] / val);
}

inline ArchEngine::Vector operator*(float val, const ArchEngine::Vector & v)
{
	return ArchEngine::Vector(val * v[0], val * v[1], val * v[2], val * v[3]);
}
