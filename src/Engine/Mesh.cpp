#include "Mesh.h"
#include "Resource.h"
#include "Entity.h"
#include "Core.h"
#include <fstream>

void Mesh::onLoad(const std::string & _path)
{
	std::string obj;
	std::string line;

	std::cout << "loading " << _path << "..."<< std::endl;

	std::string temp = std::string("../Resources/") + _path + std::string(".obj");

	std::ifstream file(temp);

	if (!file.is_open())
	{
		throw std::exception();
	}

	while (!file.eof())
	{
		std::getline(file, line);
		obj += line + "\n";
	}
	//std::shared_ptr<Core> rtn = getCore();
	std::shared_ptr<rend::Mesh> shape = getCore()->getContext()->createMesh();
	shape->parse(obj);
	mesh = shape;
	std::cout << "Finished loading " << _path << std::endl;
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