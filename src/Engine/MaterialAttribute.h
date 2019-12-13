#include <string>
#include <memory>

class Texture;

class MaterialAttribute
{
public:
	std::string name;
	int type;
	float floatValue;
	std::weak_ptr<Texture> textureValue;
};