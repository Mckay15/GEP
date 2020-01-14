#include "MeshRenderer.h"
#include "Material.h"
#include "Mesh.h"
#include "Core.h"

void MeshRenderer::onDisplay()
{
	material->buffer->add(glm::vec2(0, 0.5f));
	material->buffer->add(glm::vec2(-0.5f, -0.5f));
	material->buffer->add(glm::vec2(0.5f, -0.5f));

	material->shader->setAttribute("a_Position", material->buffer);
//	material->shader->setMesh(mesh->mesh);
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