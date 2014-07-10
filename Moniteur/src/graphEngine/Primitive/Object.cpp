//
// Object.cpp for Object in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur/graphEngine/Primitive
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Sat Jul  5 13:27:49 2014 david vallee
// Last update Thu Jul 10 11:10:03 2014 david vallee
//


#include "Object.hpp"
#define PI (3.141592653589793)

Object::Object() : AObject(0, 0, 0, 0.3) {}

bool		Object::initialize()
{
  _geometry.pushVertex(glm::vec3(0, -0.5, 0.5));
  _geometry.pushVertex(glm::vec3(0, 0.5, 0.5));
  _geometry.pushVertex(glm::vec3(0, 0.5, -0.5));
  _geometry.pushVertex(glm::vec3(0, -0.5, -0.5));
  _geometry.pushUv(glm::vec2(0.25f, 0.0f));
  _geometry.pushUv(glm::vec2(0.25f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
  _geometry.pushUv(glm::vec2(0.0f, 0.0f));
  _geometry.build();
  return (true);
}

void		Object::LoadTexture(gdl::Texture *tex)
{
}

void		Object::update(gdl::Clock const &clock, gdl::Input &input)
{  
}

double		Object::norme(glm::vec2 v)
{
  return (sqrt(v.x * v.x + v.y * v.y));
}

float		Object::scalaire(const glm::vec2 &v1, const glm::vec2 &v2)
{
  return (acos((v1.x * v2.x + v1.y * v2.y) / (norme(v1) * norme(v2))));
}

void		Object::update(gdl::Clock const &clock, gdl::Input &input, glm::vec3 _p)
{
  p = _p;
}

void		Object::draw(gdl::AShader &shader,
			     gdl::Clock const &clock)
{
}

void		Object::draw(glm::vec3 pos,
			     gdl::AShader &shader,
			     gdl::Clock const &clock)
{
  _position = pos;
  (void)clock;

  float		angle_z;
  angle_z  = scalaire(glm::vec2(0, 1), glm::vec2(_position.z - p.z, _position.x - p.x));
  if (_position.z <  p.z)
    rotate(glm::vec3(0, 1, 0), (angle_z) * 180 / PI);
  else
    rotate(glm::vec3(0, -1, 0), (angle_z) * 180 / PI);
  _geometry.draw(shader, getTransformation(), GL_QUADS);
  _rotation = glm::vec3(0, 0, 0);
}
