
#include <memory>
#include <list>

class Resource;

class Resources
{
private:
	std::list<std::shared_ptr<Resource>> resources;
public:
	template<typename T>
	std::shared_ptr<T> load(std::string path)
	{

	}
};