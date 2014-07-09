//
// Billboard.cpp for Billboard in /home/vallee_c/MiniEngine/src
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Wed Jun  4 21:18:18 2014 david vallee
// Last update Wed Jul  9 22:18:19 2014 david vallee
//

#include "Billboard.hpp"

#define PI (3.141592653589793)

Billboard::Billboard() : AObject(0, 0, 0) {}
Billboard::Billboard(float x, float y, float z) : AObject(x, y, z) {}
Billboard::Billboard(float x, float y, float z, float size, float nb, int sizeX, int sizeY) : AObject(x, y, z, size)
{
  nb_anime = nb;
  mapsizeX = sizeX;
  mapsizeZ = sizeY;
}

void		Billboard::LoadTexture(gdl::Texture *tex)
{
  _texture = tex;
}

bool		Billboard::initialize()
{
  int	i;

  _time = 0;
  anime = 1;
  orient = 0;
  rot = 0;
  _speed = 4;

  int	c = nb_anime;
  _geometry = new gdl::Geometry *[4];
  i = 0;
  while (i < 4)
    {
      _geometry[i] = new gdl::Geometry[c];
      ++i;
    } 

  int	j;

  j = 0;
  while (j < 4)
    {
      i = 0;
      while (i < nb_anime)
	{
	  float	a;
	  float	b;

	  a = i / (nb_anime);
	  b = (i + 1) / (nb_anime);
	  _geometry[j][i].pushVertex(glm::vec3(0, -0.5, 0.5));
	  _geometry[j][i].pushVertex(glm::vec3(0, 0.5, 0.5));
	  _geometry[j][i].pushVertex(glm::vec3(0, 0.5, -0.5));
	  _geometry[j][i].pushVertex(glm::vec3(0, -0.5, -0.5));
	  _geometry[j][i].pushUv(glm::vec2(b, 1.0f * j / 4.0f));
	  _geometry[j][i].pushUv(glm::vec2(b, 1.0f * j / 4.0f + 1.0f / 4.0f));
	  _geometry[j][i].pushUv(glm::vec2(a, 1.0f * j / 4.0f + 1.0f / 4.0f));
	  _geometry[j][i].pushUv(glm::vec2(a, 1.0f * j / 4.0f));
	  _geometry[j][i].build();
	   ++i;
	}
      ++j;
    }  
  return (true);
}

void		Billboard::update(gdl::Clock const &clock, gdl::Input &input)
{
  
}

double		Billboard::norme(glm::vec2 v)
{
  return (sqrt(v.x * v.x + v.y * v.y));
}

float		Billboard::scalaire(const glm::vec2 &v1, const glm::vec2 &v2)
{
  return (acos((v1.x * v2.x + v1.y * v2.y) / (norme(v1) * norme(v2))));
}

float		Billboard::abs(float a)
{
  if (a < 0)
    return (-a);
  return (a);
}

int		Billboard::getOrient(glm::vec3 p)
{
  if (p.x >= _position.x)
    {
      if (abs(p.x - _position.x) > abs(p.z - _position.z))
	return (2);
      else if (p.z > _position.z)
	return (3);
      return (1);
    }
  if (abs(p.x - _position.x) > abs(p.z - _position.z))
    return (0);
  else if (p.z > _position.z)
    return (3);
  return (1);
}

void		Billboard::update(gdl::Clock const &clock, gdl::Input &input, glm::vec3 p, float vAnime)
{
  _time += clock.getElapsed();
  if (input.getKey(SDLK_UP) == false)
    move = false;
  else
    move = true;
  
  if (move == true)
    {
      if (_time > vAnime)
	{
	  _time = 0;
	  anime++;
	}
    }
  else
    {
      _time = 0;
      anime = 1;
    }

  if (input.getKey(SDLK_LEFT) == false &&
      input.getKey(SDLK_RIGHT) == false &&
      input.getKey(SDLK_UP) == false && lastKey == false)
    lastKey = true;

  if (input.getKey(SDLK_RIGHT) && lastKey != false)
    {
      lastKey = false;
      rot--;
      if (rot < 0)
	rot = 3;
    }
  else if (input.getKey(SDLK_LEFT) && lastKey != false)
    {
      lastKey = false;
      rot++;
      if (rot > 3)
	rot = 0;
    }

  glm::vec3 dir;

  if (rot == 0)
    dir = glm::vec3(0, 0, 1);
  else if (rot == 1)
    dir = glm::vec3(1, 0, 0);
  else if (rot == 2)
    dir = glm::vec3(0, 0, -1);
  else if (rot == 3)
    dir = glm::vec3(-1, 0, 0);
  if (move)
    translate(dir * static_cast<float>(clock.getElapsed()) * _speed);
    
  if (_position.x < 1)
    _position.x = mapsizeX + 1;
  if (_position.x > mapsizeX + 1)
    _position.x = 1;
  if (_position.z < 1)
    _position.z = mapsizeZ + 1;
  if (_position.z > mapsizeZ + 1)
    _position.z = 1;

  orient = getOrient(p);
  float		angle_z;
  angle_z  = scalaire(glm::vec2(0, 1), glm::vec2(_position.z - p.z, _position.x - p.x));
  if (_position.z <  p.z)
    rotate(glm::vec3(0, 1, 0), (angle_z) * 180 / PI);
  else
    rotate(glm::vec3(0, -1, 0), (angle_z) * 180 / PI);
}

void		Billboard::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
  (void)clock;
  _texture->bind();
  if (anime > nb_anime - 1)
    anime = 0;
  int a = (orient + 1) + rot;
  if (a > 4)
    a -= 4;
  _geometry[a - 1][anime].draw(shader, getTransformation(), GL_QUADS);
  _rotation = glm::vec3(0, 0, 0);
}
