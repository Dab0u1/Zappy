//
// Billboard.cpp for Billboard in /home/vallee_c/MiniEngine/src
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Wed Jun  4 21:18:18 2014 david vallee
// Last update Thu Jul 10 17:17:06 2014 david vallee
//

#include "Trantorien.hpp"

#define PI (3.141592653589793)

Trantorien::Trantorien() : AObject(0, 0, 0) 
{
  _nb_anime = 3;
  _speed = 4; // init en fonction de t
  _orient = 0;
}

void		Trantorien::LoadTexture(gdl::Texture *tex)
{
}

bool		Trantorien::initialize()
{
  int	c;
  int	i;
  int	j;
  
  c = _nb_anime;
  _geometry = new gdl::Geometry *[4];
  i = 0;
  while (i < 4)
    {
      _geometry[i] = new gdl::Geometry[c];
      ++i;
    }
  j = 0;
  while (j < 4)
    {
      i = 0;
      while (i < _nb_anime)
	{
	  float	a;
	  float	b;

	  a = i / (_nb_anime);
	  b = (i + 1) / (_nb_anime);
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

void		Trantorien::update(gdl::Clock const &clock, gdl::Input &input)
{
  
}

double		Trantorien::norme(glm::vec2 v)
{
  return (sqrt(v.x * v.x + v.y * v.y));
}

float		Trantorien::scalaire(const glm::vec2 &v1, const glm::vec2 &v2)
{
  return (acos((v1.x * v2.x + v1.y * v2.y) / (norme(v1) * norme(v2))));
}

float		Trantorien::abs(float a)
{
  if (a < 0)
    return (-a);
  return (a);
}

int		Trantorien::getOrient(glm::vec3 p)
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

void		Trantorien::update(gdl::Clock const &clock,
				   gdl::Input &input, glm::vec3 p)
{
  _posCam = p;
}

void		Trantorien::draw(t_player *tmp, gdl::AShader &shader, gdl::Clock const &clock)
{
  tmp->time += clock.getElapsed();
  // Set la position
  _position = glm::vec3(tmp->x + 1.5, 0.5, tmp->y + 1.5);
  _scale = glm::vec3(tmp->l / 2.0f, tmp->l / 2.0f, tmp->l / 2.0f);
  
  // set L'orientation
  _orient = getOrient(_posCam);
  float		angle;
  angle  = scalaire(glm::vec2(0, 1), glm::vec2(_position.z - _posCam.z,
					       _position.x - _posCam.x));
  if (_position.z < _posCam.z)
    rotate(glm::vec3(0, 1, 0), (angle) * 180 / PI);
  else
    rotate(glm::vec3(0, -1, 0), (angle) * 180 / PI);
  int a = _orient + tmp->o;
  if (a > 4)
    a -= 4;
  // Set l'animation
  if (tmp->anime > _nb_anime - 1)
    tmp->anime = 0;
  // Bind la texture et draw
  (void)clock;
  _geometry[a - 1][tmp->anime].draw(shader, getTransformation(), GL_QUADS);
  _rotation = glm::vec3(0, 0, 0);
}

void		Trantorien::draw(gdl::AShader &shader, gdl::Clock const &clock)
{
}
