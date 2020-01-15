#include "Component.h"
#include "Keyboard.h"
#include "Environment.h"
#include "Core.h"
#include "Entity.h"

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
	return entity.lock();
}
std::shared_ptr<Core> Component::getCore() 
{
	return entity.lock()->getCore();
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

