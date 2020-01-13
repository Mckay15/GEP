#include <memory>
#include <string>
#include <vector>
#include "Resource.h"
#include "rend/rend.h"

class MeshRenderer;
class Shader;
class Texture;
class MaterialAttribute;

class Material : public Resource
{
	friend class MeshRenderer;
public:
	std::shared_ptr<Shader> getShader();
	void onLoad(const std::string& _path);
private:
	std::shared_ptr<rend::Shader> shader;
	std::shared_ptr<rend::Texture> texture;
};