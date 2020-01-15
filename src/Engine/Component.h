#ifndef _COMPONENT_H
#define _COMPONENT_H

#include <memory>

class Core;
class Environment;
class Keyboard;
class Camera;

class Component
{
	friend class Entity;
private:
	std::weak_ptr<Entity> entity;
public:
	virtual void onInit();
	virtual void onBegin();
	virtual void onTick();
	virtual void onDisplay();
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Core> getCore();
	std::shared_ptr<Keyboard> getKeyboard();
	std::shared_ptr<Environment> getEnviroment();
	std::shared_ptr<Camera> getCamera();
};


#endif // !_COMPONENT_H
