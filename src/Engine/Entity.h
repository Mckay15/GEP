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
	template<typename T> std::shared_ptr<T> addComponent();

	Entity();
	~Entity();
};

#endif // _ENTITY_H