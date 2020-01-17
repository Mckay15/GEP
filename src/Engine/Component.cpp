#include "Component.h"
#include "Core.h"
#include "Entity.h"
/**
*\brief Virtual onInit
*/
void Component::onInit()
{
}

/**
*\brief Virtual onBegin
*/
void Component::onBegin()
{
}

/**
*\brief Virtual onTick
*/
void Component::onTick()
{
}

/**
*\brief Virtual onDisplay
*/
void Component::onDisplay()
{
}

/**
*\brief Gets Components Entity reference
*\return shared_ptr of Entity
*/
std::shared_ptr<Entity> Component::getEntity()
{
	return entity.lock();
}

/**
*\brief Gets the core
*\return Gets core through Entity
*/
std::shared_ptr<Core> Component::getCore() 
{
	return entity.lock()->getCore();
}


