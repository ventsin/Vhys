#pragma once
#include "Vector.hpp"
#include "Body.hpp"
#include "Callback.hpp"
#include <vector>
#include <chrono>
//#include <map>

namespace vh
{
	class World
	{
	public:
		World();
		World(Vector gravity);
		~World();

		void setGravity(Vector gravity);
		Body* registerBody(Vector pos, Vector size, float mass, bool isDynamic = false, BodyID = 0);
		void registerCallback(Callback&);

		void update();

	private:
		Callback* m_call;
		bool m_hascallback = false;
		Vector m_gravity;
		std::vector<Body> m_bodies;
		std::vector<Contact*> m_contacts;
		std::chrono::steady_clock::time_point start;
		//start = std::chrono::high_resolution_clock::now();
	};
}
