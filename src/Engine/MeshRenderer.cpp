#include "MeshRenderer.h"

void MeshRenderer::onDisplay()
{
}

void MeshRenderer::onInit()
{
}

void MeshRenderer::setMesh(std::weak_ptr<Mesh> _mesh)
{
}

std::shared_ptr<Mesh> MeshRenderer::getMesh()
{
	return std::shared_ptr<Mesh>();
}

std::shared_ptr<Material> MeshRenderer::getMaterial()
{
	return std::shared_ptr<Material>();
}
