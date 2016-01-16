#pragma once
#include "Vector.hpp"
#include "Callback.hpp"

namespace vh
{
	typedef unsigned int BodyID;

	BodyID generateID();

	class Body
	{
	public:
		Body();
		~Body();
		void move(Vector);
		Vector m_position, m_size;
		float m_mass;
		bool m_dynamic;
		BodyID m_id;
		Vector m_movement;
	};
}
