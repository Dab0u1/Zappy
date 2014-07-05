//
// Ground.cpp for Ground in /home/vallee_c/Zappy/Moniteur/graphEngine/Primitive
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Fri Jul  4 17:55:01 2014 david vallee
// Last update Sat Jul  5 12:46:54 2014 david vallee
//

#include "Ground.hpp"

Ground::Ground() : AObject(0, 0, 0)
{
  size_x = 20;
  size_y = 20;
  s = 1;
}

Ground::Ground(float x, float y, float z, int sx, int sy) : AObject(x, y, z)
{
  size_x = sx;
  size_y = sy;
}

Ground::~Ground() {}

void	Ground::LoadTexture(gdl::Texture *tex)
{
  _texture = tex;
}

bool	Ground::initialize()
{
  int	x;
  int	y;

  y = 0;
  while (y < size_y)
    {
      x = 0;
      while (x < size_x)
	{
	  _geometry.setColor(glm::vec4(1, 1, 1, 1));
	  _geometry.pushVertex(glm::vec3(x * s + s, 0, y * s));
	  _geometry.pushVertex(glm::vec3(x * s + s, 0, y * s + s));
	  _geometry.pushVertex(glm::vec3(x * s, 0, y * s + s));
	  _geometry.pushVertex(glm::vec3(x * s, 0, y * s));
	  _geometry.pushUv(glm::vec2(0.05f, 0.05f));
	  _geometry.pushUv(glm::vec2(0.95f, 0.05f));
	  _geometry.pushUv(glm::vec2(0.95f, 0.95f));
	  _geometry.pushUv(glm::vec2(0.05f, 0.95f));
	  ++x;
	}
      ++y;
    }
  _geometry.build();
  return (true);
}

void	Ground::update(gdl::Clock const &clock, gdl::Input &input)
{
}

void	Ground::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture->bind();
  _geometry.draw(shader, getTransformation(), GL_QUADS);
}
