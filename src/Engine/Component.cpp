#include "Component.h"
#include "Core.h"

std::shared_ptr<Entity> Component::getEntity()
{
	return std::make_shared<Entity>();
}
std::shared_ptr<Core> Component::getCore() 
{
	return std::make_shared<Core>();
}
std::shared_ptr<Keyboard> Component::getKeyboard()
{
	return std::make_shared<Keyboard>();
}
std::shared_ptr<Environment> Component::getEnviroment()
{
	return std::make_shared<Environment>();
}