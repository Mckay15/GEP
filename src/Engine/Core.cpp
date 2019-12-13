#include "Core.h"
#include "Entity.h"

std::shared_ptr<Core> Core::initialize()
{
	std::shared_ptr<Core> Temp = std::make_shared<Core>();

	Temp->self = Temp;

	return Temp;
}
std::shared_ptr<Entity> Core::addEntity()
{
	return std::make_shared<Entity>();
}

void Core::start()
{
	
}
void Core::stop()
{

}

Core::Core()
{

}
Core::~Core()
{

}