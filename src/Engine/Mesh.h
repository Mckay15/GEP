#include "Resource.h"
#include "rend/rend.h"
#include <vector>

class MeshRenderer;

/**
*\brief Represents the Mesh
*/
class Mesh : public Resource
{
	friend class MeshRenderer;
public:
	void onLoad(const std::string& _path);
	Mesh();
	~Mesh();
private:
	std::shared_ptr<rend::Mesh> mesh; ///< Holds a Mesh from rend
};