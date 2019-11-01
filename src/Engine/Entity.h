#ifndef _ENTITY_H
#define _ENTITY_H

#include <memory>
#include <list>
#include <glm/glm.hpp>

class Core;
class Component;

class Entity
{
private:
	std::list<std::shared_ptr<Component>> components;
	std::weak_ptr<Core> core;
	void tick();
	void display();
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
public:
	std::shared_ptr<Core> getCore();
	template<typename T, typename... args> 
	std::shared_ptr<T> addComponent()
	{
		std::shared_ptr<T> component = std::make_shared<T>();
		//std::shared_ptr<Component> temp = std::make_shared<Component>();
		//temp = std::dynamic_pointer_cast<Component>(component);

		if (!component)
		{
			throw std::exception();
		}
		components.push_back(component);
		return component;	
	}

	template<typename T> 
	std::shared_ptr<T> getComponent()
	{
		for (auto it = components.begin(); it != components.end(); it++)
		{
			std::shared_ptr<T> rtn = std::dynamic_pointer_cast<T>(*it);
			if (rtn)
			{
				return rtn;
			}
		}
		throw std::exception();
	}

	Entity();
	~Entity();
};

#endif // _ENTITY_H