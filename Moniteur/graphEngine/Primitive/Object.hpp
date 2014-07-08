//
// Object.hpp for Object in /home/vallee_c/rendu/PSU_2013_zappy/Moniteur/graphEngine/Primitive
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Sat Jul  5 13:28:41 2014 david vallee
// Last update Tue Jul  8 15:40:00 2014 david vallee
//

#ifndef OBJECT_HPP_
# define OBJECT_HPP_

# include "../AObject.hpp"
# include "../engine.h"

class	Object : public AObject
{
private:
  gdl::Geometry _geometry;
  glm::vec3	p;

public:
  Object();
  virtual ~Object() {}
  virtual void		LoadTexture(gdl::Texture *);
  virtual bool		initialize();
  virtual void		update(gdl::Clock const &, gdl::Input &);
  int			getOrient(glm::vec3 p);
  void			update(gdl::Clock const &clock, gdl::Input &input,
			       glm::vec3 v2);
  virtual void		draw(gdl::AShader &, gdl::Clock const &);
  void			draw(glm::vec3 pos, gdl::Texture *_texture, gdl::AShader &, gdl::Clock const &);

private:
  double	norme(glm::vec2 v);
  float		scalaire(const glm::vec2 &v1, const glm::vec2 &v2);
};

#endif /* !OBJECT_HPP_ */
