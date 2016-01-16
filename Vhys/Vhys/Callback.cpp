#include "Callback.hpp"
using namespace vh;


Callback::Callback()
{
}


Callback::~Callback()
{
}

Body * vh::Contact::GetBodyA()
{
	return A;
}

Body * vh::Contact::GetBodyB()
{
	return B;
}
