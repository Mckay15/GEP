#include "MeshRenderer.h"
#include "Material.h"
#include "Mesh.h"
#include "Core.h"
#include "Camera.h"

void MeshRenderer::onDisplay()
{
//	material->shader->setAttribute("a_Position", material->buffer);
	//material->shader->setMesh(mesh->mesh);
	mesh->mesh->setTexture("u_Texture", material->texture);

	material->shader->setUniform("u_Projection", getCore()->getCamera()->getProjection());
	material->shader->setUniform("u_Model", getCore()->getCamera()->getView());
	material->shader->render();
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
	//mesh->mesh->setTexture("u_Texture", material->texture);
}