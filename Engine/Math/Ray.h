#pragma once

#include "Vector3.h"

namespace ArchEngine
{
	class Ray
	{
	public:
		Ray() = default;

		Ray(Vector3 origin, Vector3 direction) :
			m_origin(origin),
			m_direction(unit_vector(direction))
		{ }

		const Vector3 GetOrigin() const { return m_origin; }
		const Vector3 GetDirection() const { return m_direction; }

	private:
		Vector3 m_origin;
		Vector3 m_direction;
	};
}