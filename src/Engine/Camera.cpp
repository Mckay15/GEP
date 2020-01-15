#include "Camera.h"
#include "Core.h"

void Camera::onInit()
{
	
}

void Camera::onDisplay()
{
}

glm::mat4 Camera::getProjection()
{ 
	return glm::perspective(glm::radians(65.0f), 1.0f, 0.1f, 100.0f);
}

glm::mat4 Camera::getView()
{
	return glm::inverse(getEntity()->getModel());
}
