/*
** Plan.cpp for Plan in /home/vallee_c/BomberMan/EngineTest/MiniEngine/src/Primitive
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Wed May  7 07:49:35 2014 david vallee
// Last update Fri May 16 03:37:26 2014 david vallee
*/

#include "Plan.hpp"

Plan::Plan() {}
Plan::Plan(float x, float y, float z) : AObject(x, y, z) {}
Plan::Plan(float x, float y, float z, float scale) : AObject(x, y, z, scale) {}
Plan::~Plan() {}

void	Plan::LoadTexture(gdl::Texture *tex)
{
  _texture = tex;
}

bool	Plan::initialize()
{
  // _geometry.setColor(glm::vec4(1, 1, 1, 1));
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

void	Plan::update(gdl::Clock const &clock, gdl::Input &input)
{
  if (input.getKey(SDLK_n))
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
    }
}

void	Plan::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture->bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
