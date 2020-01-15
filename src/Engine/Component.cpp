#include "Component.h"
#include "Keyboard.h"
#include "Environment.h"
#include "Core.h"

void Component::onInit()
{
}

void Component::onBegin()
{
}

void Component::onTick()
{
}

void Component::onDisplay()
{
}

std::shared_ptr<Entity> Component::getEntity()
{
	std::shared_ptr<Entity> entity = std::make_shared<Entity>();

	return entity;
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

std::shared_ptr<Camera> Component::getCamera()
{
	return std::shared_ptr<Camera>();
}

