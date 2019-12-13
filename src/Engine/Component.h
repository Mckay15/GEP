#ifndef _COMPONENT_H
#define _COMPONENT_H

#include "Entity.h"
#include <memory>

class Entity;
class Core;
class Environment;
class Keyboard;

class Component
{
	friend class Entity;
private:
	std::weak_ptr<Entity> entity;
	virtual void onInit() = 0;
	virtual void onBegin() = 0;
	virtual void onTick() = 0;
	virtual void onDisplay() = 0;
	glm::vec3 localPos;
	glm::vec3 localRot;
	glm::vec3 localScale;
public:
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Core> getCore();
	std::shared_ptr<Keyboard> getKeyboard();
	std::shared_ptr<Environment> getEnviroment();
	void translate(glm::vec3 _distance);
	void roatate(glm::vec3 _rotation);
	void scale(glm::vec3 _scale);
	void setLocalPos(glm::vec3 _pos);
	void setLocalRot(glm::vec3 _rot);
	void setLocalScale(glm::vec3 _scale);
};


#endif // !_COMPONENT_H
