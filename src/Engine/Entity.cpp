#include "Entity.h"


void Entity::tick()
{

}
void Entity::display()
{

}

template<typename T> std::shared_ptr<T> Entity::addComponent()
{
	std::shared_ptr<Component> component = std::shared_ptr(T);
	components.push_back(component);
	return woof;
}

std::shared_ptr<Core> Entity::getCore()
{

}

Entity::Entity()
{

}
Entity::~Entity()
{

}