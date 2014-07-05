/*
** Plan.hpp for Plan in /home/vallee_c/BomberMan/EngineTest/MiniEngine/src/Primitive
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Wed May  7 07:49:38 2014 david vallee
** Last update Thu May  8 12:38:37 2014 david vallee
*/

#ifndef PLAN_HPP_
# define PLAN_HPP_

# include "../engine.h"

class	Plan : public AObject
{
private:
  gdl::Texture	*_texture;
  gdl::Geometry _geometry;

public:
  Plan();
  Plan(float x, float y, float z);
  Plan(float x, float y, float z, float);
  virtual ~Plan();
  virtual void	LoadTexture(gdl::Texture *);
  virtual bool	initialize();
  virtual void	update(gdl::Clock const &, gdl::Input &);
  virtual void	draw(gdl::AShader &, gdl::Clock const &);
};

#endif /* !PLAN_HPP_ */
