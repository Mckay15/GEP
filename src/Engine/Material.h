#include <memory>
#include <string>
#include <vector>

class Shader;
class Texture;
class MaterialAttribute;

class Material
{
public:
	void setShader(std::weak_ptr<Shader> _shader);
	void setValue(std::string _name, std::weak_ptr<Texture> _value);
	void setValue(std::string _name, float _value);
	std::shared_ptr<Shader> getShader();
private:
	std::weak_ptr<Shader> shader;
	std::vector<MaterialAttribute> attributes;
};