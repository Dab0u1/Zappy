/*
** AObject.cpp for AObject in /home/vallee_c/BomberMan/EngineTest/MiniEngine/src
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Wed May  7 07:45:50 2014 david vallee
// Last update Sat Jul  5 11:46:11 2014 david vallee
*/

#include "AObject.hpp"

AObject::AObject() :
  _position(0, 0, 0),
  _rotation(0, 0, 0),
  _scale(1, 1, 1)
{
}

AObject::AObject(float x, float y, float z) :
  _position(x, y, z),
  _rotation(0, 0, 0),
  _scale(1, 1, 1)
{
}

AObject::AObject(float x, float y, float z, float size) :
  _position(x, y, z),
  _rotation(0, 0, 0),
  _scale(size, size, size)
{
}

AObject::AObject(glm::vec3 const &v) :
  _position(v.x, v.y, v.z),
  _rotation(0, 0, 0),
  _scale(1, 1, 1)
{
}

AObject::AObject(glm::vec3 const &v1, glm::vec3 const &v2, glm::vec3 const &v3) :
  _position(v1.x, v1.y, v1.z),
  _rotation(v2.x, v2.y, v2.z),
  _scale(v3.x, v3.y, v3.z)
{
}
  
AObject::~AObject(){}

void		AObject::translate(glm::vec3 const &v)
{
  _position += v;
}

void		AObject::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}

void		AObject::scale(glm::vec3 const& scale)
{
  _scale *= scale;
}

glm::mat4	AObject::getTransformation()
{
  glm::mat4	transform(1);

  transform = glm::translate(transform, _position);
  transform = glm::rotate(transform, _rotation.x, glm::vec3(1, 0, 0));
  transform = glm::rotate(transform, _rotation.y, glm::vec3(0, 1, 0));
  transform = glm::rotate(transform, _rotation.z, glm::vec3(0, 0, 1));
  transform = glm::scale(transform, _scale);
  return (transform);
}

glm::vec3	AObject::getPosition()
{
  return (_position);
};
