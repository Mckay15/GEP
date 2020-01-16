#ifndef _ENTITY_H
#define _ENTITY_H

#include <memory>
#include <list>
#include <glm/glm.hpp>
#include "Component.h"

/**
*  Represents a Gameobject
*/

class Entity
{
	friend class Core;
private:
	std::list<std::shared_ptr<Component>> components; ///< stores the Gameobjects components
	std::weak_ptr<Core> core; ///< keeps a reference to core
	std::weak_ptr<Entity> self; ///< keeps a refenece to it self to give to components
	void tick();
	void display(); 
	glm::vec3 localPos = glm::vec3(0,0,0); ///< keeps local position gets set to 0 by default
	glm::vec3 localRot = glm::vec3(0,0,0); ///< keeps local rotation gets set to 0 by default
	glm::vec3 localScale = glm::vec3(1,1,1); ///< keeps local scale gets set to 1 by default, 0 results in not seeing anything
public:

	std::shared_ptr<Core> getCore();
	/**
	*\brief AddComponent will store a component and initate component, allows for addtional parameters for onInit() 
	*/
	template<typename T, typename... A> 
	std::shared_ptr<T> addComponent(A... args)
	{
		std::shared_ptr<T> component = std::make_shared<T>();
		if (!component)
		{
			throw std::exception();
		}
		component->entity = self;
		components.push_back(component);
		component->onInit(args...);
		return component;	
	}
	/**
	*\brief goes through components till it finds required type defined by template
	*/
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

	void translate(glm::vec3 _distance);
	void rotate(glm::vec3 _rotation);
	void scale(glm::vec3 _scale);
	void setLocalPos(glm::vec3 _pos);
	void setLocalRot(glm::vec3 _rot);
	void setLocalScale(glm::vec3 _scale);
	glm::mat4 getModel();

	Entity();
	~Entity();
};

#endif // _ENTITY_H