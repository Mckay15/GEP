#include <memory>
#include <string>

class Core;
class Mesh;

class Resource
{
private:
	std::weak_ptr<Core> core;
public:
	//friend class Resources;
	std::shared_ptr<Core> getCore();
	virtual std::shared_ptr<Mesh> onLoad(const std::string& path)
	{}
};