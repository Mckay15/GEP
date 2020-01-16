#include <memory>
#include "rend/rend.h"
#include "Component.h"

class Mesh;
class Material;

/**
*\brief Represents a MeshRenderer
*Renders Entities materials and mesh
*/
class MeshRenderer : public Component
{
private:
	std::shared_ptr<Mesh> mesh; ///< Holds mesh
	std::shared_ptr<Material> material;///< Holds Material
public:
	void onDisplay();
	void onInit();
	void setMesh(std::shared_ptr<Mesh> _mesh);
	void setMaterial(std::shared_ptr<Material> _material);
};