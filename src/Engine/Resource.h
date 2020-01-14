#ifndef _RESOURCE_H_
#define _RESOURCE_H_

#include <memory>
#include <string>
#include "NonCopyable.h"

class Core;
class Mesh;

class Resource : private NonCopyable
{
	friend class Resources;
private:
	std::weak_ptr<Core> core;
public:
	std::shared_ptr<Core> getCore();
	virtual void onLoad(const std::string& path)
	{}
};

#endif // !_RESOURCE_H_