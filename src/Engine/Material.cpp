#define STB_IMAGE_IMPLEMENTATION
#include "rend/stb_image.h"

#include "Material.h"
#include "Core.h"
#include <exception>
#include "rend/rend.h"

std::shared_ptr<Shader> Material::getShader()
{
	return std::shared_ptr<Shader>();
}

void Material::onLoad(const std::string & _path)
{
	std::shared_ptr<rend::Shader> rtnS = getCore()->getContext()->createShader();


	std::shared_ptr<rend::Texture> rtnT = getCore()->getContext()->createTexture();

	{
		int w = 0;
		int h = 0;
		int bpp = 0;

		unsigned char *data = stbi_load(_path.c_str(),
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

				texture->setPixel(x, y, glm::vec3(
					data[r] / 255.0f,
					data[r + 1] / 255.0f,
					data[r + 2] / 255.0f));
			}
		}

		stbi_image_free(data);
	}
	texture = rtnT;
}
