#include "World.hpp"
using namespace vh;


World::World() :
	start(std::chrono::high_resolution_clock::now())
{
}

World::World(Vector gravity) :
	start(std::chrono::high_resolution_clock::now())
{
	m_gravity = gravity;
}

World::~World()
{
	std::vector<Contact*>::iterator it;
	for (it = m_contacts.begin(); it != m_contacts.end(); )
	{
		delete * it;
		it = m_contacts.erase(it);
	}
}

void World::setGravity(Vector gravity)
{
	m_gravity = gravity;
}

void vh::World::registerBody(Vector pos, Vector size, float mass, bool isDynamic = false, BodyID id = 0)
{
	Body b;
	b.m_position = pos;
	b.m_size = size;
	b.m_mass = mass;
	b.m_dynamic = isDynamic;
	if (id == 0)
		b.m_id = generateID();
	else
		b.m_id = id;
	m_bodies.push_back(b);
}

void vh::World::registerCallback(Callback &call)
{
	m_call = &call;
	m_hascallback = true;
}

void vh::World::update()
{
	long long time = std::chrono::duration_cast<std::chrono::seconds>(std::chrono::high_resolution_clock::now() - start).count();

	for (auto &i : m_bodies)
	{
		i.m_movement.x += m_gravity.x;
		i.m_movement.y += m_gravity.y;

		i.move(Vector(i.m_movement.x * time, i.m_movement.y * time));
	}

	if (!m_contacts.empty())
		for (auto &i : m_contacts)
		{
			if (i->GetBodyA()->m_position.x < i->GetBodyB()->m_position.x + i->GetBodyB()->m_size.x
				|| i->GetBodyA()->m_position.x + i->GetBodyA()->m_size.x > i->GetBodyB()->m_position.x
				|| i->GetBodyA()->m_position.y < i->GetBodyB()->m_position.y + i->GetBodyB()->m_size.y
				|| i->GetBodyA()->m_position.y + i->GetBodyA()->m_size.y > i->GetBodyB()->m_position.y)
			{
				if (!m_hascallback)
				{
					if (i->GetBodyA()->m_position.x < i->GetBodyB()->m_position.x + i->GetBodyB()->m_size.x)
					{

					}
				}
			}
		}

	for (auto &i : m_bodies)
	{
		for (auto &j : m_bodies)
		{
			if (i.m_id != j.m_id)
				if (i.m_position.x < j.m_position.x + j.m_size.x || i.m_position.x + i.m_size.x > j.m_position.x
					|| i.m_position.y < j.m_position.y + j.m_size.y || i.m_position.y + i.m_size.y > j.m_position.y)

		}
	}

	start = std::chrono::high_resolution_clock::now();
}
