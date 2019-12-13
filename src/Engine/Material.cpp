#include "Material.h"

void Material::setShader(std::weak_ptr<Shader> _shader)
{
}

void Material::setValue(std::string _name, std::weak_ptr<Texture> _value)
{
}

void Material::setValue(std::string _name, float _value)
{
}

std::shared_ptr<Shader> Material::getShader()
{
	return std::shared_ptr<Shader>();
}
