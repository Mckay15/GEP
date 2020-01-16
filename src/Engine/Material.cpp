#define STB_IMAGE_IMPLEMENTATION
#include "rend/stb_image.h"
#include "rend/rend.h"

#include "Material.h"
#include "Core.h"
#include <exception>
#include <iostream>
#include <fstream>

/**
*\brief Loads a shader and Texture 
*\param _path is name of file name for the shader and texture
*This function will load a shader and texture from resources.
*_path just need to be the file name without the file extension.
*/
void Material::onLoad(const std::string& _path)
{
	std::shared_ptr<rend::Shader> rtnS = getCore()->getContext()->createShader();

	std::string shaderStr;

	std::string temp = std::string("../Resources/") + _path + std::string(".shader");

	std::ifstream file(temp.c_str());

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
			shaderStr += line + "\n";
		}
	}
	file.close();

	rtnS->parse(shaderStr);
	
	shader = rtnS;

	std::cout << "Finished" << std::endl;

	std::sr1::shared_ptr<rend::Texture> rtnT = getCore()->getContext()->createTexture();

	int w = 0;
	int h = 0;
	int bpp = 0;

	temp.clear();
	temp = std::string("../Resources/") + _path + std::string(".png");

	unsigned char *data = stbi_load(temp.c_str(),
		&w, &h, &bpp, 3);

	if (!data)
	{
		throw std::exception();
	}

	rtnT->setSize(w, h);

	for (int y = 0; y < h; y++)
	{
		for (int x = 0; x < w; x++)
		{
			int r = y * w * 3 + x * 3;

			rtnT->setPixel(x, y, glm::vec3(
				data[r] / 255.0f,
				data[r + 1] / 255.0f,
				data[r + 2] / 255.0f));
		}
	}

	stbi_image_free(data);

	texture = rtnT;
}
