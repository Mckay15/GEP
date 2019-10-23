#include "Entity.h"
#include "Core.h"


void Entity::tick()
{

}
void Entity::display()
{

}

std::shared_ptr<Core> Entity::getCore()
{
	return std::make_shared<Core>();
}

Entity::Entity()
{

}
Entity::~Entity()
{

}