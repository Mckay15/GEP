#include <memory>
#include <Engine/Core.h>
#include <Engine/Entity.h>
#include <Engine/Component.h>

int main ()
{
	std::shared_ptr<Core> Temp = Core::initialize();
	std::shared_ptr<Entity> entity = Temp->addEntity();

	auto keyboard = entity->addComponent<Keyboard>();
return 0;
}