#include "Core.h"
#include "Entity.h"
#include "Resources.h"
#include <exception>

/**
*\brief SetCamera sets the camera
*\param _camera this is the camera that you want to set as the main camera
*No auto camera setup
*/
void Core::setCamera(std::shared_ptr<Camera> _camera)
{
	camera = _camera;
}

/**
*\brief Returns cores Resources ptr
*/
std::shared_ptr<Resources> Core::getResources()
{
	return resources;
}

/**
*\brief Returns cores Camera ptr
*/
std::shared_ptr<Camera> Core::getCamera()
{
	return camera.lock();
}

/**
*\brief Returns cores Context ptr
*/
std::shared_ptr<rend::Context> Core::getContext()
{
	return context;
}

/**
*\brief This is called first to setup core
* It returns a reference of it self that should be used to add entities or camera's
*Setups up SDL_Window, rend::Context, and makes a Resources
*/
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

	Temp->glContext = SDL_GL_CreateContext(Temp->window);

	if (!Temp->glContext)
	{
		throw std::exception("Failed to create OpenGL context");
	}

	Temp->context = rend::Context::initialize();

	Temp->resources = std::make_shared<Resources>();

	Temp->resources->selfCore = Temp;

	return Temp;
}

/**
*\brief Creates and adds Entity to game
*Creates a Entity
*\returns Entity that was created
*/
std::shared_ptr<Entity> Core::addEntity()
{
	std::shared_ptr<Entity> rtn = std::make_shared<Entity>();
	rtn->self = rtn;
	rtn->core = self;
	entities.push_back(rtn);
	return rtn;
}

/**
*\brief Starts game loop
*When called starts game loop
*/
void Core::start()
{
	SDL_Event e = { 0 };
	while (running)
	{
		while (SDL_PollEvent(&e) != 0)
		{
			if (e.type == SDL_QUIT)
			{
				running = false;
			}
		}
		//std::cout << "RUNNING" << std::endl;
		glClearColor(0.39f, 0.58f, 0.93f, 1.0f);
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

		for (auto it = entities.begin(); it != entities.end(); it++)
		{
			(*it)->display();
		}

		SDL_GL_SwapWindow(window);
	}
}

/**
*\brief Stops the game all together
*/
void Core::stop()
{
	SDL_GL_DeleteContext(glContext);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

/**
*\brief Core empty constructor
*/
Core::Core()
{

}

/**
*\brief Core empty destructor
*/
Core::~Core()
{

}