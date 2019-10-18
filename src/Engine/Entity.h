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
	template<typename T>
	std::shared_ptr<T> addComponent(T A, T B, T C)
	{
		std::shared_ptr<Component> woof = A;
		components.push_back(woof);
		return woof;
	}

	Entity();
	~Entity();
};