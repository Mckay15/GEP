#include <memory>
#include <Engine/Core.h>
#include <Engine/Entity.h>
#include <Engine/Component.h>
#include <Engine/Keyboard.h>
#include <Engine/Camera.h>
#include <Engine/MeshRenderer.h>
#include <Engine/Mesh.h>

int main ()
{
	std::shared_ptr<Core> Temp = Core::initialize();
	std::shared_ptr<Entity> entity = Temp->addEntity();
	std::shared_ptr<Entity> entity2 = Temp->addEntity();

	auto meshRen = entity2->addComponent<MeshRenderer>();
	auto keyboard = entity->addComponent<Keyboard>();
return 0;
}