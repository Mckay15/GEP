#include "Entity.h"
#include "Core.h"
#include "Component.h"


void Entity::tick()
{
	
}
void Entity::display()
{
	for (auto it = components.begin(); it != components.end(); it++)
	{
		//std::shared_ptr<Component> rtn = std::dynamic_pointer_cast<Component>(*it);
		(*it)->onDisplay();
	}
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