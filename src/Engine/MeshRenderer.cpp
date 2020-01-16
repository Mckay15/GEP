#include "MeshRenderer.h"
#include "Material.h"
#include "Mesh.h"
#include "Core.h"
#include "Camera.h"
#include "Entity.h"

/**
*\brief Displays Entities material and mesh
*Gets Projection matrix and view matrix from the camera.
*Gets called to render
*/
void MeshRenderer::onDisplay()
{
	mesh->mesh->setTexture("u_Texture", material->texture);
	
	material->shader->setUniform("u_Projection", getCore()->getCamera()->getProjection());
	material->shader->setUniform("u_Model", getCore()->getCamera()->getView(getEntity()));
	material->shader->setMesh(mesh->mesh);
	material->shader->render();
}

/**
*\brief Sets mesh
*\param _mesh is a shared_ptr of mesh
*/
void MeshRenderer::setMesh(std::shared_ptr<Mesh> _mesh)
{
	mesh = _mesh;
}

/**
*\brief Sets Material
*\param _material is a shared_ptr of material
*/
void MeshRenderer::setMaterial(std::shared_ptr<Material> _material)
{
	material = _material;
}

void MeshRenderer::onInit()
{

	//mesh->mesh->setTexture("u_Texture", material->texture);
}