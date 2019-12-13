#ifndef _CORE_H
#define _CORE_H

#include <memory>
#include <List>
#include "NonCopyable.h"
#include <SDL2/SDL.h>
#include <rend/rend.h>
#include <AL/al.h>
#include <AL/alc.h>

class Entity;
class Keyboard;
class Environment;

class Core : private NonCopyable
{
private:
	std::shared_ptr<Environment> environment;
	std::list<std::shared_ptr<Entity>> entities;
	std::shared_ptr<Keyboard> keyboard;
	bool running = true;
	std::weak_ptr<Core> self;
	ALCcontext* audioContext;
public:
	static std::shared_ptr<Core> initialize();
	std::shared_ptr<Entity> addEntity();
	void start();
	void stop();

	Core();
	~Core();
};

#endif // !_CORE_H