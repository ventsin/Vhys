#pragma once
#include "Body.hpp"

namespace vh
{
	class Contact
	{
	public:
		// Get the first body in this contact
		Body* GetBodyA();

		// Get the second body in this contact
		Body* GetBodyB();

	private:
		Body* A;
		Body* B;
	};

	class Callback
	{
	public:
		Callback();
		~Callback();
		// Some collision happened
		virtual void beginContact(Contact* contact) = 0;
		// Some collision just finished
		virtual void endContact(Contact* contact) = 0;
	};
}
