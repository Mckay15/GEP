#define STB_IMAGE_IMPLEMENTATION
#include "rend/stb_image.h"

#include "Material.h"
#include "Core.h"
#include <exception>
#include <fstream>
#include "rend/rend.h"


void Material::onLoad(const std::string& _path)
{
	std::shared_ptr<rend::Shader> rtnS = getCore()->getContext()->createShader();

	std::string shader;

	std::ifstream file(_path.c_str());

	std::cout << "Loading... " << std::endl;
	if (!file.is_open())
	{
		throw std::exception();
	}
	else
	{
		while (!file.eof())
		{
			std::string line;
			std::getline(file, line);
			shader += line + "\n";
		}
	}
	file.close();

	rtnS->parse(shader);
	
	std::cout << "Finished" << std::endl;

	buffer = getCore()->getContext()->createBuffer();
}