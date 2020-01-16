#include "Camera.h"
#include "Core.h"
#include "Entity.h"

/**
*\brief Gets the Projection Matrix
*\return Persective matix
*/
glm::mat4 Camera::getProjection()
{ 
	return glm::perspective(glm::radians(65.0f), 1.0f, 0.1f, 100.0f);
}

/**
*\brief Gets view matrix
*\param _entity is the entity you need th position of
*\return inverse of the model matix 
*/
glm::mat4 Camera::getView(std::shared_ptr<Entity> _entity)
{
	return glm::inverse(_entity->getModel());
}
