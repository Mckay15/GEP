
#include <memory>
#include <list>

class Resource;

/**
*\brief Represents Resources class
*Loads resource class and get reference to core to pass to resource
*/
class Resources
{
	friend class Core;
private:
	std::list<std::shared_ptr<Resource>> resources; ///< Holds a list of resource
public:
	std::weak_ptr<Core> selfCore; ///< Holds weak_ptr to core
	
	/**
	*\brief loads a resource
	*\param path will be name of file you want to load
	*loads a resource of with material or mesh, passes reference for core
	*calls onLoad and pass through the path to load that file
	*\return shared_ptr of resource
	*/
	template<typename T>
	std::shared_ptr<T> load(std::string path)
	{
		std::shared_ptr<T> rtn;
		rtn = std::make_shared<T>();
		rtn->core = selfCore;
		rtn->onLoad(path);
		return rtn;
	}
};