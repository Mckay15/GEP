#include "Material.h"
#include "MaterialAttribute.h"

void Material::setShader(std::weak_ptr<Shader> _shader)
{
	shader = _shader;
}

void Material::setValue(std::string _name, std::weak_ptr<Texture> _value)
{
	MaterialAttribute mat;
	mat.name = _name;
	mat.textureValue = _value;
	attributes.push_back(mat);
}

void Material::setValue(std::string _name, float _value)
{
	MaterialAttribute mat;
	mat.name = _name;
	mat.floatValue = _value;
	attributes.push_back(mat);
}

std::shared_ptr<Shader> Material::getShader()
{
	return std::shared_ptr<Shader>();
}
