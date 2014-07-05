/*
** Plan.cpp for Plan in /home/vallee_c/BomberMan/EngineTest/MiniEngine/src/Primitive
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Wed May  7 07:49:35 2014 david vallee
// Last update Fri May 16 02:47:05 2014 david vallee
*/

#include "Plan.hpp"

Anim2D::Anim2D() {}
Anim2D::Anim2D(glm::vec3 const &v) : AObject(x, y, z) {}
Anim2D::Anim2D(glm::vec3 const &v1,
	       glm::vec3 const &v2,
	       glm::vec3 const &v3) : AObject(v1, v2, v3) {}
Anim2D::~Anim2D() {}

void	Anim2D::LoadTexture(gdl::Texture *tex)
{
  _texture = tex;
}

bool	Anim2D::initialize()
{
  _geometry.pushVertex(glm::vec3(1, 0, 0));
  _geometry.pushVertex(glm::vec3(1, 0, 1));
  _geometry.pushVertex(glm::vec3(0, 0, 1));
  _geometry.pushVertex(glm::vec3(0, 0, 0));
  _geometry.pushUv(glm::vec2(0.05f, 0.05f));
  _geometry.pushUv(glm::vec2(0.95f, 0.05f));
  _geometry.pushUv(glm::vec2(0.95f, 0.95f));
  _geometry.pushUv(glm::vec2(0.05f, 0.95f));
  _geometry.build();
  return (true);
}

void	Anim2D::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (input.getKey(SDLK_n))
    {
      _geometry.pushUv(glm::vec2(0.05f, 0.05f));
      _geometry.pushUv(glm::vec2(0.95f, 0.05f));
      _geometry.pushUv(glm::vec2(0.95f, 0.95f));
      _geometry.pushUv(glm::vec2(0.05f, 0.95f));
      _geometry.build();
    }
}

void	Anim2D::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture->bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
