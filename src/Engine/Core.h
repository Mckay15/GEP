#ifndef _CORE_H
#define _CORE_H

#include <memory>
#include <List>
#include "Environment.h"
#include "Entity.h"
#include "Keyboard.h"


class Core
{
private:
	std::shared_ptr<Environment> environment;
	std::list<std::shared_ptr<Entity>> entities;
	std::shared_ptr<Keyboard> keyboard;
	bool running = true;
public:
	std::shared_ptr<Core> initialize();
	std::shared_ptr<Entity> addEntity();

	void start();
	void stop();

	Core();
	~Core();
};

#endif // !_CORE_H