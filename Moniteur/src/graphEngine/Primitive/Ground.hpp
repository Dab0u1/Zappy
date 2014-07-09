//
// Ground.hpp for Ground in /home/vallee_c/Zappy/Moniteur/graphEngine/Primitive
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Fri Jul  4 17:52:36 2014 david vallee
// Last update Fri Jul  4 18:48:38 2014 david vallee
//

#ifndef GROUND_HPP_
# define GROUND_HPP_

# include "../engine.h"
# include "../AObject.hpp"

class	Ground : public AObject
{
private:
  gdl::Texture	*_texture;
  gdl::Geometry _geometry;
  int		size_x;
  int		size_y;
  int		s;

public:
  Ground();
  Ground(float, float, float, int, int);
  virtual ~Ground();
  virtual void	LoadTexture(gdl::Texture *);
  virtual bool	initialize();
  virtual void	update(gdl::Clock const &, gdl::Input &);
  virtual void	draw(gdl::AShader &, gdl::Clock const &);
};

#endif /* !GROUND_HPP_ */
