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
class Resources;
class Camera;
/**
*\brief Represents the core
*The core will control and run the other systems
*/

class Core : private NonCopyable
{
private:
	std::list<std::shared_ptr<Entity>> entities; ///< Each entity is stored to run through later
	std::shared_ptr<Resources> resources; ///< Holds a reference to Resources
	std::weak_ptr<Camera> camera; ///< Holds a reference to camera 
	bool running = true;  ///< bool to say it is running
	std::weak_ptr<Core> self; ///< a weak_ptr to itself to give to others
	std::shared_ptr<rend::Context> context; ///< reference to context for multiple objects to access
	SDL_Window* window; ///< SDL_Window store location, setup in initalize
	SDL_GLContext glContext;
public:
	void setCamera(std::shared_ptr<Camera> _camera);
	std::shared_ptr<Resources> getResources();
	std::shared_ptr<Camera> getCamera();
	std::shared_ptr<rend::Context> getContext();
	static std::shared_ptr<Core> initialize();
	std::shared_ptr<Entity> addEntity();
	void start();
	void stop();

	Core();
	~Core();
};

#endif // !_CORE_H