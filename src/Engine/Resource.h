#include <memory>
#include <string>

class Core;

class Resource
{
private:
	std::weak_ptr<Core> core;

public:
	virtual void onLoad(const std::string& path){}
};