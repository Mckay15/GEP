#ifndef _RESOURCE_H_
#define _RESOURCE_H_

#include <memory>
#include <string>
#include "NonCopyable.h"

class Core;
class Mesh;

class Resource : private NonCopyable
{
private:
	std::weak_ptr<Core> core;
public:
	//friend class Resources;
	std::shared_ptr<Core> getCore();
	void onLoad(const std::string& path)
	{}
};

#endif // !_RESOURCE_H_