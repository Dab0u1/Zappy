//
// Object.cpp for Object in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur/graphEngine/Primitive
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Sat Jul  5 13:27:49 2014 david vallee
// Last update Sat Jul  5 13:32:40 2014 david vallee
//


#include "Object.hpp"
#define PI (3.141592653589793)

Object::Object() : AObject(0, 0, 0) {}
Object::Object(float x, float y, float z) : AObject(x, y, z) {}
Object::Object(float x, float y, float z, float size, float nb) : AObject(x, y, z, size)
{
  nb_anime = nb;
}

void		Object::LoadTexture(gdl::Texture *tex)
{
  _texture = tex;
}

bool		Object::initialize()
{
  _time = 0;
  anime = 0;

  int	c = nb_anime;
  _geometry = new gdl::Geometry[c];
  
  int	i;
  i = 0;
  while (i < nb_anime)
    {
      float	a;
      float	b;
      
      a = i / (nb_anime);
      b = (i + 1) / (nb_anime);
      _geometry[i].pushVertex(glm::vec3(0, -0.5, 0.5));
      _geometry[i].pushVertex(glm::vec3(0, 0.5, 0.5));
      _geometry[i].pushVertex(glm::vec3(0, 0.5, -0.5));
      _geometry[i].pushVertex(glm::vec3(0, -0.5, -0.5));
      _geometry[i].pushUv(glm::vec2(b, 0.0f));
      _geometry[i].pushUv(glm::vec2(b, 1.0f));
      _geometry[i].pushUv(glm::vec2(a, 1.0f));
      _geometry[i].pushUv(glm::vec2(a, 0.0f));
      _geometry[i].build();
      ++i;
    }
  return (true);
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

void		Object::update(gdl::Clock const &clock, gdl::Input &input, glm::vec3 p, float vAnime)
{
  _time += clock.getElapsed();
  if (_time > vAnime)
    {
      _time = 0;
      anime++;
    }
  float		angle_z;
  angle_z  = scalaire(glm::vec2(0, 1), glm::vec2(_position.z - p.z, _position.x - p.x));
  if (_position.z <  p.z)
    rotate(glm::vec3(0, 1, 0), (angle_z) * 180 / PI);
  else
    rotate(glm::vec3(0, -1, 0), (angle_z) * 180 / PI);
}

void		Object::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture->bind();
  if (anime > nb_anime - 1)
    anime = 0;
  _geometry[anime].draw(shader, getTransformation(), GL_QUADS);
  _rotation = glm::vec3(0, 0, 0);
}
