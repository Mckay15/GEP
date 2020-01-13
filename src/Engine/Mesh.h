#include "Resource.h"
#include "NonCopyable.h"
#include "rend/rend.h"
#include <vector>

class Core;

class Mesh : public Resource//, private NonCopyable
{
public:
	virtual std::shared_ptr<Mesh> onLoad(const std::string& _path);
	Mesh();
	~Mesh();
	void addFace(rend::Face& _face);
	GLuint getId();
private:
	bool dirty;
	std::vector<rend::Face> faces;
	virtual std::shared_ptr<Mesh> create();

};