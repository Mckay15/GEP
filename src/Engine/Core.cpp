#include "Core.h"


std::shared_ptr<Core> Core::initialize()
{
	return std::make_shared<Core>();
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