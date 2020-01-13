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
	return core.lock();
}

Entity::Entity()
{

}
Entity::~Entity()
{

}