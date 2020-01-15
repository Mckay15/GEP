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

glm::mat4 Entity::getModel()
{
	glm::mat4 model = glm::mat4(1);

	model = glm::translate(model, localPos);
	model = glm::rotate(model, localRot.x, glm::vec3(1, 0, 0));
	model = glm::rotate(model, localRot.y, glm::vec3(0, 1, 0));
	model = glm::rotate(model, localRot.z, glm::vec3(0, 0, 1));
	model = glm::scale(model, localScale);
	return model;
}

void Entity::translate(glm::vec3 _distance)
{
	localPos += _distance;
}

void Entity::rotate(glm::vec3 _rotation)
{
	localRot += _rotation;
}

void Entity::scale(glm::vec3 _scale)
{
	localScale += _scale;
}

void Entity::setLocalPos(glm::vec3 _pos)
{
	localPos = _pos;
}

void Entity::setLocalRot(glm::vec3 _rot)
{
	localRot = _rot;
}

void Entity::setLocalScale(glm::vec3 _scale)
{
	localScale = _scale;
}