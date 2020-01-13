#include "Core.h"
#include "Entity.h"
#include "Resources.h"
#include <exception>

std::shared_ptr<rend::Context> Core::getContext()
{
	return context;
}

std::shared_ptr<Core> Core::initialize()
{
	std::shared_ptr<Core> Temp = std::make_shared<Core>();

	Temp->self = Temp;

	Temp->window = SDL_CreateWindow("Rend Rotate Test",
		SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED,
		800, 600,
		SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

	if (!Temp->window)
	{
		throw std::exception("Failed to create window");
	}

	SDL_GLContext glContext = SDL_GL_CreateContext(Temp->window);

	if (!glContext)
	{
		throw std::exception("Failed to create OpenGL context");
	}

	Temp->context = rend::Context::initialize();

	Temp->resources = std::make_shared<Resources>();

	Temp->resources->selfCore = Temp;

	return Temp;
}
std::shared_ptr<Entity> Core::addEntity()
{
	return std::make_shared<Entity>();
}

void Core::start()
{
	
}
void Core::stop()
{

}

Core::Core()
{

}
Core::~Core()
{

}