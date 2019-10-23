#include "Entity.h"
#include <memory>

class Entity;
class Core;
class Keyboard;
class Environment;

class Component
{
private:
	std::weak_ptr<Entity> entity;
	virtual void onInit() = 0;
	virtual void onBegin() = 0;
	virtual void onTick() = 0;
	virtual void onDisplay() = 0;

public:
	std::shared_ptr<Entity> getEntity();
	std::shared_ptr<Core> getCore();
	std::shared_ptr<Keyboard> getKeyboard();
	std::shared_ptr<Environment> getEnviroment();

};