//
// Ground.cpp for Ground in /home/vallee_c/Zappy/Moniteur/graphEngine/Primitive
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Fri Jul  4 17:55:01 2014 david vallee
// Last update Sun Jul  6 11:05:55 2014 david vallee
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
  s = 1;
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
  int	z;

  y = 1;
  while (y <= size_y)
    {
      x = 1;
      while (x <= size_x)
	{
	  _geometry.setColor(glm::vec4(1, 1, 1, 1));
	  _geometry.pushVertex(glm::vec3(x * s + s, 0, y * s));
	  _geometry.pushVertex(glm::vec3(x * s + s, 0, y * s + s));
	  _geometry.pushVertex(glm::vec3(x * s, 0, y * s + s));
	  _geometry.pushVertex(glm::vec3(x * s, 0, y * s));

	  if (y == 1)
	    {
	      if (x == 1)
		{
		  // border down left
		  _geometry.pushUv(glm::vec2(0.67f, 1.0f));
		  _geometry.pushUv(glm::vec2(0.67f, 1.0f - 0.16f));
		  _geometry.pushUv(glm::vec2(0.99f, 1.0f - 0.16f));
		  _geometry.pushUv(glm::vec2(0.99f, 1.0f));
		}
	      else if (x == size_x)
		{
		  //border down right
		  _geometry.pushUv(glm::vec2(0.0f, 1.0f));
		  _geometry.pushUv(glm::vec2(0.0f, 1.0f - 0.16f));
		  _geometry.pushUv(glm::vec2(0.32f, 1.0f - 0.16f));
		  _geometry.pushUv(glm::vec2(0.32f, 1.0f));
		}
	      else
		{
		  // border down mid
		  _geometry.pushUv(glm::vec2(0.333f, 1.0f));
		  _geometry.pushUv(glm::vec2(0.333f, 1.0f - 0.16f));
		  _geometry.pushUv(glm::vec2(0.666f, 1.0f - 0.16f));
		  _geometry.pushUv(glm::vec2(0.666f, 1.0f));
		}
	      // Mountain !!
	      z = -2;
	      while (z < 1)
		{
		  _geometry.setColor(glm::vec4(1, 1, 1, 1));
		  _geometry.pushVertex(glm::vec3(x * s, z, 1));
		  _geometry.pushVertex(glm::vec3(x * s, z - 1, 1));
		  _geometry.pushVertex(glm::vec3(x * s + s, z - 1, 1));
		  _geometry.pushVertex(glm::vec3(x * s + s, z, 1));	
		  _geometry.pushUv(glm::vec2(0.333f, 0.5f + z * 0.1666f));
		  _geometry.pushUv(glm::vec2(0.333f, 0.5f + z * 0.1666f - 0.1666f));
		  _geometry.pushUv(glm::vec2(0.666f, 0.5f + z * 0.1666f - 0.1666f));
		  _geometry.pushUv(glm::vec2(0.666f, 0.5f + z * 0.1666f));
		  ++z;
		}
	    }
	  else if (x == (size_x) && y != 1 && y != size_y)
	    {
	      // border left mid
	      _geometry.pushUv(glm::vec2(0.001f, 1.0f - 0.16f));
	      _geometry.pushUv(glm::vec2(0.001f, 1.0f - 0.32f));
	      _geometry.pushUv(glm::vec2(0.32f, 1.0f - 0.32f));
	      _geometry.pushUv(glm::vec2(0.32f, 1.0f - 0.16f));
	    }
	  else if (x == 1 && y != 1 && y != size_y)
	    { 
	      // border right mid
	      _geometry.pushUv(glm::vec2(0.67f, 1.0f - 0.16f));
	      _geometry.pushUv(glm::vec2(0.67f, 1.0f - 0.32f));
	      _geometry.pushUv(glm::vec2(0.99f, 1.0f - 0.32f));
	      _geometry.pushUv(glm::vec2(0.99f, 1.0f - 0.16f));
	    }
	  else if (y == size_y)
	    {
	      if (x == 1)
		{
		  //border up left
		  _geometry.pushUv(glm::vec2(0.32f, 1.0f - 0.21f));
		  _geometry.pushUv(glm::vec2(0.32f, 1.0f - 0.001f));
		  _geometry.pushUv(glm::vec2(0.001f, 1.0f - 0.001f));
		  _geometry.pushUv(glm::vec2(0.001f, 1.0f - 0.21f));
		}
	      else if (x == size_x)
		{
		  //border up right
		  _geometry.pushUv(glm::vec2(0.99f, 1.0f - 0.16f));
		  _geometry.pushUv(glm::vec2(0.99f, 1.0f - 0.0f));
		  _geometry.pushUv(glm::vec2(0.67f, 1.0f - 0.0f));
		  _geometry.pushUv(glm::vec2(0.67f, 1.0f - 0.16f));
		}
	      else
		{
		  //border up mid
		  _geometry.pushUv(glm::vec2(0.63f, 1.0f - 0.16f));
		  _geometry.pushUv(glm::vec2(0.63f, 1.0f - 0.0f));
		  _geometry.pushUv(glm::vec2(0.34f, 1.0f - 0.0f));
		  _geometry.pushUv(glm::vec2(0.34f, 1.0f - 0.16f));
		}
	      z = -2;
	      while (z <= 0)
		{
		  // Mountain !!
		  _geometry.setColor(glm::vec4(1, 1, 1, 1));
		  _geometry.pushVertex(glm::vec3(x * s, z, size_y + 1));
		  _geometry.pushVertex(glm::vec3(x * s, z - 1, size_y + 1));
		  _geometry.pushVertex(glm::vec3(x * s + s, z - 1, size_y + 1));
		  _geometry.pushVertex(glm::vec3(x * s + s, z, size_y + 1));	
		  _geometry.pushUv(glm::vec2(0.333f, 0.5f + z * 0.1666f));
		  _geometry.pushUv(glm::vec2(0.333f, 0.5f + z * 0.1666f - 0.1666f));
		  _geometry.pushUv(glm::vec2(0.666f, 0.5f + z * 0.1666f - 0.1666f));
		  _geometry.pushUv(glm::vec2(0.666f, 0.5f + z * 0.1666f));
		  ++z;
		}
	    }
	  else
	    {
	      //center
	      _geometry.pushUv(glm::vec2(0.34f, 1.0f - 0.21f));
	      _geometry.pushUv(glm::vec2(0.34f, 1.0f - 0.39f));
	      _geometry.pushUv(glm::vec2(0.65f, 1.0f - 0.39f));
	      _geometry.pushUv(glm::vec2(0.65f, 1.0f - 0.21f));
	    }

	  if (x == (size_x))
	    {
	      z = -2;
	      while (z <= 0)
		{
		  _geometry.setColor(glm::vec4(1, 1, 1, 1));
		  _geometry.pushVertex(glm::vec3(size_x + 1, z, y * s));
		  _geometry.pushVertex(glm::vec3(size_x + 1, z - 1, y * s));
		  _geometry.pushVertex(glm::vec3(size_x + 1, z - 1, y * s + s));
		  _geometry.pushVertex(glm::vec3(size_x + 1, z, y * s + s));	
		  _geometry.pushUv(glm::vec2(0.333f, 0.5f + z * 0.1666f));
		  _geometry.pushUv(glm::vec2(0.333f, 0.5f + z * 0.1666f - 0.1666f));
		  _geometry.pushUv(glm::vec2(0.666f, 0.5f + z * 0.1666f - 0.1666f));
		  _geometry.pushUv(glm::vec2(0.666f, 0.5f + z * 0.1666f));
		  ++z;
		}
	    }
	  else if (x == 1)
	    {
	      z = -2;
	      while (z <= 0)
		{
		  _geometry.setColor(glm::vec4(1, 1, 1, 1));
		  _geometry.pushVertex(glm::vec3(1, z, y * s));
		  _geometry.pushVertex(glm::vec3(1, z - 1, y * s));
		  _geometry.pushVertex(glm::vec3(1, z - 1, y * s + s));
		  _geometry.pushVertex(glm::vec3(1, z, y * s + s));	
		  _geometry.pushUv(glm::vec2(0.333f, 0.5f + z * 0.1666f));
		  _geometry.pushUv(glm::vec2(0.333f, 0.5f + z * 0.1666f - 0.1666f));
		  _geometry.pushUv(glm::vec2(0.666f, 0.5f + z * 0.1666f - 0.1666f));
		  _geometry.pushUv(glm::vec2(0.666f, 0.5f + z * 0.1666f));
		  ++z;
		}
	    }
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
