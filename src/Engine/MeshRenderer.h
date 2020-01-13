#include <memory>
#include "rend/rend.h"
#include "Component.h"

class Mesh;
class Material;

class MeshRenderer : public Component
{
private:
	std::shared_ptr<Mesh> mesh;
	std::shared_ptr<Material> material;
public:
	void onDisplay();
	void onInit();
	void setMesh(std::shared_ptr<Mesh> _mesh);
	void setMaterial(std::shared_ptr<Material> _material);
};