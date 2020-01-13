#include "Mesh.h"
#include "Resource.h"
#include "Entity.h"
#include "Core.h"
#include <fstream>

void Mesh::onLoad(const std::string & _path)
{
	std::ifstream f(_path);
	std::string obj;
	std::string line;

	while (!f.eof())
	{
		std::getline(f, line);
		obj += line + "\n";
	}
	//std::shared_ptr<Core> rtn = getCore();
	std::shared_ptr<rend::Mesh> shape = getCore()->getContext()->createMesh();
	shape->parse(obj);
	mesh = shape;
	//return std::make_shared<Mesh>();
}

Mesh::Mesh()
{
}

Mesh::~Mesh()
{
}

void Mesh::addFace(rend::Face& _face)
{
	faces.push_back(_face);
}

GLuint Mesh::getId()
{
	return GLuint();
}