#ifndef _RESOURCE_H_
#define _RESOURCE_H_

#include <memory>
#include <string>
#include "NonCopyable.h"

class Core;
class Mesh;

/**
*\brief Represents Resource class
*/
class Resource : private NonCopyable
{
	friend class Resources;
private:
	std::weak_ptr<Core> core; ///< Holds Weak ptr to core
public:
	std::shared_ptr<Core> getCore();

	/**
	*\brief Virtual function for onload look at Mesh and Material
	*\param path will be name of file you want to load
	*/
	virtual void onLoad(const std::string& path)
	{}
};

#endif // !_RESOURCE_H_