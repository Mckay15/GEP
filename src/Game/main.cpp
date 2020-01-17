#include <memory>
#include <Engine/Material.h>
#include <Engine/Core.h>
#include <Engine/Entity.h>
#include <Engine/Component.h>
#include <Engine/Camera.h>
#include <Engine/MeshRenderer.h>
#include <Engine/Mesh.h>
#include <Engine/Resources.h>
#include <Engine/Resource.h>
#include <Engine/Camera.h>

int main ()
{
	std::shared_ptr<Core> Temp = Core::initialize();

	std::shared_ptr<Entity> cameraObject = Temp->addEntity();
	std::shared_ptr<Entity> entity = Temp->addEntity();
	std::shared_ptr<Entity> entity2 = Temp->addEntity();
	std::shared_ptr<Entity> Car = Temp->addEntity();
	auto carRen = Car->addComponent<MeshRenderer>();;
	Car->setLocalPos(glm::vec3(0,0,10));
	Car->setLocalRot(glm::vec3(1, 1, 1));
	auto meshRen = entity2->addComponent<MeshRenderer>();
	entity2->setLocalPos(glm::vec3(-2.5, 0, 10));
	entity2->setLocalRot(glm::vec3(0, -0.5, 0));
	auto meshRen2 = entity->addComponent<MeshRenderer>();
	entity->setLocalPos(glm::vec3(2.5, 0, 10));

	//cameraObject->getComponent<Camera>()->getCamera();
	Temp->setCamera(cameraObject->addComponent<Camera>());
	cameraObject->setLocalPos(glm::vec3(0, 0, 10));
	//std::shared_ptr<Resources> ReSource = std::make_shared<Resources>();
	std::shared_ptr<Mesh> cat = Temp->getResources()->load<Mesh>("curuthers");
	entity2->getComponent<MeshRenderer>()->setMesh(cat);
	std::shared_ptr<Material> mat = Temp->getResources()->load<Material>("curuthers");
	entity2->getComponent<MeshRenderer>()->setMaterial(mat);

	std::shared_ptr<Mesh> car = Temp->getResources()->load<Mesh>("Car");
	Car->getComponent<MeshRenderer>()->setMesh(car);
	std::shared_ptr<Material> carmat = Temp->getResources()->load<Material>("Car");
	Car->getComponent<MeshRenderer>()->setMaterial(carmat);

	std::shared_ptr<Mesh> cat2;
	cat2 = Temp->getResources()->load<Mesh>("curuthers2");
	entity->getComponent<MeshRenderer>()->setMesh(cat2);
	std::shared_ptr<Material> mat2;
	mat2 = Temp->getResources()->load<Material>("curuthers2");
	entity->getComponent<MeshRenderer>()->setMaterial(mat2);
	//entity2->getComponent<MeshRenderer>()->onInit();

	//entity2->addComponent<Keyboard>();

	Temp->start();
	Temp->stop();
return 0;
}