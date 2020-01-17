#include "Entity.h"
#include "Core.h"
#include "Component.h"
/**
*\brief gets called each frame to got through components to go through movements/actions
*/
void Entity::tick()
{
	
}
/**
*\brief gets called each frame to go through components to display them
*/
void Entity::display()
{
	for (auto it = components.begin(); it != components.end(); it++)
	{
		(*it)->onDisplay();
	}
}

/**
*\brief Gets core reference
*/
std::shared_ptr<Core> Entity::getCore()
{
	return core.lock();
}

/**
*\brief Empty constructor 
*/
Entity::Entity()
{

}

/**
*\brief Empty destructor
*/
Entity::~Entity()
{

}

/**
*\brief Creates and returns model matrix
*Creates a model matrix and returns it.
Translate to moves it to its space.
Rotate puts it to its rotation and has to be done seperatly for each axis
Scale put changes its size 1 being normal 0 being nothing
*/
glm::mat4 Entity::getModel()
{
	glm::mat4 model = glm::mat4(1);

	model = glm::rotate(model, localRot.x, glm::vec3(1, 0, 0));
	model = glm::rotate(model, localRot.y, glm::vec3(0, 1, 0));
	model = glm::rotate(model, localRot.z, glm::vec3(0, 0, 1));
	model = glm::translate(model, localPos);
	model = glm::scale(model, localScale);
	return model;
}

/**
*\brief Changes localPos
*\param _distance distance that you want to move per frame
*/
void Entity::translate(glm::vec3 _distance)
{
	localPos += _distance;
}

/**
*\brief Changes localRot
*\param _rotation Rotation that you want to rotate per frame
*/
void Entity::rotate(glm::vec3 _rotation)
{
	localRot += _rotation;
}

/**
*\brief Changes localScale
*\param _scale Scale factor that you want to scale per frame
*/
void Entity::scale(glm::vec3 _scale)
{
	localScale += _scale;
}

/**
*\brief Sets localPos
*\param _pos A glm::vec3 that will replace localPos 
*/
void Entity::setLocalPos(glm::vec3 _pos)
{
	localPos = _pos;
}

/**
*\brief Sets localRot
*\param _rot A glm::vec3 that will replace localRot
*/
void Entity::setLocalRot(glm::vec3 _rot)
{
	localRot = _rot;
}

/**
*\brief Sets localScale
*\param _scale A glm::vec3 that will replace localScale
*/
void Entity::setLocalScale(glm::vec3 _scale)
{
	localScale = _scale;
}