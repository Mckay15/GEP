
#include <memory>
#include <list>

class Resource;
class Core;

class Resources
{
private:
	std::list<std::shared_ptr<Resource>> resources;
public:
	std::weak_ptr<Core> selfCore;
	template<typename T>
	std::shared_ptr<T> load(std::string path)
	{
		std::shared_ptr<T> rtn;
		rtn = std::make_shared<T>();
		rtn->core = selfCore;
		rtn->onLoad(path);
		return rtn;
	}
	template<typename T>
	std::shared_ptr<T> create()
	{

	}
};