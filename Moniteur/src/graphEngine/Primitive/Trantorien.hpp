//
// Trantorien.hpp for zappy in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur/src/graphEngine/Primitive
// 
// Made by david vallee
// Login   <vallee_c@epitech.net>
// 
// Started on  Thu Jul 10 10:59:43 2014 david vallee
// Last update Thu Jul 10 11:59:24 2014 david vallee
//


#ifndef TRANTORIEN_HPP_
# define TRANTORIEN_HPP_

# include "../AObject.hpp"
# include "../engine.h"
# include "../../Players/Players.hpp"

class	Trantorien : public AObject
{
private:
  gdl::Geometry **_geometry;

  glm::vec3	_posCam;
  float		_nb_anime;
  float		_speed;
  int		_orient;
  
  double	norme(glm::vec2 v);
  float		scalaire(const glm::vec2 &v1, const glm::vec2 &v2);
  float		abs(float a);

public:
  Trantorien();
  virtual ~Trantorien() {}
  virtual void		LoadTexture(gdl::Texture *);
  virtual bool		initialize();
  virtual void		update(gdl::Clock const &, gdl::Input &);
  int			getOrient(glm::vec3 p);
  void			update(gdl::Clock const &clock, gdl::Input &input,
			       glm::vec3 posCam);
  void			draw(t_player *, gdl::AShader &, gdl::Clock const &);
  virtual void		draw(gdl::AShader &, gdl::Clock const &);
};

#endif /* !TRANTORIEN_HPP_ */
