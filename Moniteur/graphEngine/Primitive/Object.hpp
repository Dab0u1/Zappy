//
// Object.hpp for Object in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur/graphEngine/Primitive
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Sat Jul  5 13:28:41 2014 david vallee
// Last update Sat Jul  5 13:29:03 2014 david vallee
//

#ifndef OBJECT_HPP_
# define OBJECT_HPP_

# include "../AObject.hpp"
# include "../engine.h"

class	Object : public AObject
{
private:
  gdl::Texture *_texture;
  gdl::Geometry *_geometry;

  float		_time;
  float		nb_anime;
  int		anime;

  double	norme(glm::vec2 v);
  float		scalaire(const glm::vec2 &v1, const glm::vec2 &v2);

public:
  Object();
  Object(float x, float y, float z);
  Object(float x, float y, float z, float size, float nb);
  virtual ~Object() {}
  virtual void		LoadTexture(gdl::Texture *);
  virtual bool		initialize();
  virtual void		update(gdl::Clock const &, gdl::Input &);
  int			getOrient(glm::vec3 p);
  void			update(gdl::Clock const &clock, gdl::Input &input,
			       glm::vec3 v2, float vAnime);
  virtual void		draw(gdl::AShader &, gdl::Clock const &);
};

#endif /* !OBJECT_HPP_ */
