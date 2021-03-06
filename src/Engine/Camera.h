#ifndef _CAMERA_H_
#define _CAMERA_H_

#include "rend/rend.h"
#include "Component.h"

/**
*\brief Represents a Camera
*/
class Camera : public Component
{
	friend class Core;
public:
	glm::mat4 getProjection();
	glm::mat4 getView(std::shared_ptr<Entity> _entity);
};
#endif //!_CAMERA_H_