#include "MeshRenderer.h"
#include "Mesh.h"

void MeshRenderer::onDisplay()
{
}

void MeshRenderer::setMesh(std::shared_ptr<Mesh> _mesh)
{
	mesh = _mesh;
}

void MeshRenderer::setMaterial(std::shared_ptr<Material> _material)
{
	material = _material;
}

void MeshRenderer::onInit()
{
	
}