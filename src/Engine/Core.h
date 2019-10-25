#ifndef _CORE_H
#define _CORE_H

#include <memory>
#include <List>
class Entity;
class Keyboard;
class Environment;


class Core
{
private:
	std::shared_ptr<Environment> environment;
	std::list<std::shared_ptr<Entity>> entities;
	std::shared_ptr<Keyboard> keyboard;
	bool running = true;
public:
	static std::shared_ptr<Core> initialize();
	std::shared_ptr<Entity> addEntity();

	void start();
	void stop();

	Core();
	~Core();
};

#endif // !_CORE_H