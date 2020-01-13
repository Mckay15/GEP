#include "Mesh.h"
#include "Core.h"
#include <fstream>

std::shared_ptr<Mesh> Mesh::onLoad(const std::string & _path)
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
	return std::shared_ptr<Mesh>();
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

std::shared_ptr<Mesh> Mesh::create()
{
	std::shared_ptr<Mesh> rtn = std::make_shared<Mesh>();
	return rtn;
}
