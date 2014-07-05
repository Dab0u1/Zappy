/*
** Cube.cpp for Cube in /home/vallee_c/BomberMan/EngineTest/MiniEngine/src/Primitive
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Wed May  7 07:49:45 2014 david vallee
// Last update Sat Jul  5 12:48:42 2014 david vallee
*/

#include "Skybox.hpp"

Skybox::Skybox() : AObject(0, 0, 0) {}
Skybox::Skybox(float x, float y, float z) : AObject(x, y, z) {}
Skybox::Skybox(float x, float y, float z, float size) : AObject(x, y, z, size) {}

void		Skybox::LoadTexture(gdl::Texture *tex)
{
  _texture = tex;
}

bool		Skybox::initialize()
{
  // ?
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(1, 0, 1));
  _geometry.pushVertex(glm::vec3(1, 1, 1));
  _geometry.pushVertex(glm::vec3(0, 1, 1));
  _geometry.pushVertex(glm::vec3(0, 0, 1));

  _geometry.pushUv(glm::vec2(0.0f, 2.0f / 3.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f / 3.0f));
  _geometry.pushUv(glm::vec2(0.25f, 1.0f / 3.0f));
  _geometry.pushUv(glm::vec2(0.25f, 2.0f / 3.0f));

  // ?
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(1, 0, 0));
  _geometry.pushVertex(glm::vec3(1, 1, 0));
  _geometry.pushVertex(glm::vec3(0, 1, 0));
  _geometry.pushVertex(glm::vec3(0, 0, 0));
  _geometry.pushUv(glm::vec2(0.75f, 2.0f / 3.0f));
  _geometry.pushUv(glm::vec2(0.75f, 1.0f / 3.0f));
  _geometry.pushUv(glm::vec2(0.5f, 1.0f / 3.0f));
  _geometry.pushUv(glm::vec2(0.5f, 2.0f / 3.0f));

  // ?
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(1, 0, 0));
  _geometry.pushVertex(glm::vec3(1, 1, 0));
  _geometry.pushVertex(glm::vec3(1, 1, 1));
  _geometry.pushVertex(glm::vec3(1, 0, 1));
  _geometry.pushUv(glm::vec2(0.75f, 2.0f / 3.0f));
  _geometry.pushUv(glm::vec2(0.75f, 1.0f / 3.0f));
  _geometry.pushUv(glm::vec2(1.0f, 1.0f / 3.0f));
  _geometry.pushUv(glm::vec2(1.0f, 2.0f / 3.0f));

  // ?
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(0, 0, 1));
  _geometry.pushVertex(glm::vec3(0, 1, 1));
  _geometry.pushVertex(glm::vec3(0, 1, 0));
  _geometry.pushVertex(glm::vec3(0, 0, 0));
  _geometry.pushUv(glm::vec2(0.25f, 2.0f / 3.0f));
  _geometry.pushUv(glm::vec2(0.25f, 1.0f / 3.0f));
  _geometry.pushUv(glm::vec2(0.50f, 1.0f / 3.0f));
  _geometry.pushUv(glm::vec2(0.50f, 2.0f / 3.0f));


  // UP
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(1.0f, 1.0f, 1.0f));
  _geometry.pushVertex(glm::vec3(1.0f, 1.0f, 0));
  _geometry.pushVertex(glm::vec3(0, 1.0f, 0));
  _geometry.pushVertex(glm::vec3(0, 1.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.25f, 0.0f));
  _geometry.pushUv(glm::vec2(0.50f, 0.0f));
  _geometry.pushUv(glm::vec2(0.50f, 1.0f / 3.0f));
  _geometry.pushUv(glm::vec2(0.25f, 1.0f / 3.0f));

  // DOWN
  _geometry.setColor(glm::vec4(1, 1, 1, 1));
  _geometry.pushVertex(glm::vec3(1.0f, 0, 0));
  _geometry.pushVertex(glm::vec3(1.0f, 0, 1.0f));
  _geometry.pushVertex(glm::vec3(0, 0, 1.0f));
  _geometry.pushVertex(glm::vec3(0, 0, 0));


  _geometry.pushUv(glm::vec2(0.5f, 1.0f));
  _geometry.pushUv(glm::vec2(0.25f, 1.0f));
  _geometry.pushUv(glm::vec2(0.25f, 2.0f / 3.0f));
  _geometry.pushUv(glm::vec2(0.5f, 2.0f / 3.0f));

  _geometry.build();
  return (true);
}

void		Skybox::update(gdl::Clock const &clock, gdl::Input &input)
{

}

void		Skybox::update(gdl::Clock const &clock, gdl::Input &input, glm::vec3 p)
{
  _position = (p - glm::vec3(_scale.x / 2, _scale.y / 2, _scale.z / 2));

}

void		Skybox::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture->bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
