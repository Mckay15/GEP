#ifndef _COMPONENT_H
#define _COMPONENT_H

#include <memory>

class Core;
class Environment;
class Keyboard;
class Camera;

/**
*\brief Represents Component class
*/
class Component
{
	friend class Entity;
private:
	std::weak_ptr<Entity> entity; ///< Holds a reference to entity its attached to
public:
	virtual void onInit();
	virtual void onBegin();
	virtual void onTick();
	virtual void onDisplay();
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Core> getCore();
};


#endif // !_COMPONENT_H
