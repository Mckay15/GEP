#include "Component.h"
#include "Keyboard.h"
#include "Environment.h"
#include "Core.h"

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

void Component::translate(glm::vec3 _distance)
{
}

void Component::roatate(glm::vec3 _rotation)
{
}

void Component::scale(glm::vec3 _scale)
{
}

void Component::setLocalPos(glm::vec3 _pos)
{
}

void Component::setLocalRot(glm::vec3 _rot)
{
}

void Component::setLocalScale(glm::vec3 _scale)
{
}
