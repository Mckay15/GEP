#include "Resource.h"
//#include "NonCopyable.h"
#include "rend/rend.h"
#include <vector>

//class Core;
class MeshRenderer;

class Mesh : public Resource //, private NonCopyable
{
	friend class MeshRenderer;
public:
	void onLoad(const std::string& _path);
	Mesh();
	~Mesh();
	void addFace(rend::Face& _face);
	GLuint getId();
private:
	std::shared_ptr<rend::Mesh> mesh;
	bool dirty;
	std::vector<rend::Face> faces;
};