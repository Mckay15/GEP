#include <memory>
#include <string>
#include <vector>
#include "Resource.h"
#include "rend/rend.h"

class MeshRenderer;
class Shader;
class Texture;
class MaterialAttribute;

/**
*\brief Represents Material class
*Loads Shaders and Textures
*/
class Material : public Resource
{
	friend class MeshRenderer;
public:
	void onLoad(const std::string& _path);
private:
	std::shared_ptr<rend::Shader> shader; ///< Holds the rend::Shader you get from onLoad
	std::shared_ptr<rend::Texture> texture; ///< Holds the rend::Texture you get from onLoad
};