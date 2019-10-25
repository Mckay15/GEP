#ifndef _ENTITY_H
#define _ENTITY_H

#include <memory>
#include <list>

class Core;
class Component;

class Entity
{
private:
	std::list<std::shared_ptr<Component>> components;
	std::weak_ptr<Core> core;
	void tick();
	void display();
public:
	std::shared_ptr<Core> getCore();
	template<typename T, typename... args> std::shared_ptr<T> addComponent()
	{
		std::shared_ptr<Component> component = std::make_shared<T>();
		//std::shared_ptr<Component> temp = std::make_shared<Component>();
		//temp = std::dynamic_pointer_cast<Component>(component);

		if (!component)
		{
			std::exception();
		}
		components.push_back(component);
		return component;
		
	}

	Entity();
	~Entity();
};

#endif // _ENTITY_H