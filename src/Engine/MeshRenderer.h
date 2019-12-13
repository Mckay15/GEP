#include <memory>

class Mesh;
class Material;

class MeshRenderer
{
private:
	std::weak_ptr<Mesh> mesh;
	std::shared_ptr<Material> material;
	void onDisplay();
public:
	void onInit();
	void setMesh(std::weak_ptr<Mesh> _mesh);
	std::shared_ptr<Mesh> getMesh();
	std::shared_ptr<Material> getMaterial();
};