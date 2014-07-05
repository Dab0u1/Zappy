/*
** Cube.hpp for Cube in /home/vallee_c/BomberMan/EngineTest/MiniEngine/src/Primitive
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Wed May  7 07:49:49 2014 david vallee
** Last update Wed May  7 11:20:33 2014 david vallee
*/

#ifndef CUBE_HPP_
# define CUBE_HPP_

# include "../engine.h"

class	Cube : public AObject
{
private:
  gdl::Texture *_texture;
  gdl::Geometry _geometry;

public:
  Cube();
  Cube(float x, float y, float z);
  Cube(float x, float y, float z, float size);
  virtual ~Cube() {}
  virtual void		LoadTexture(gdl::Texture *);
  virtual bool		initialize();
  virtual void		update(gdl::Clock const &, gdl::Input &);
  virtual void		draw(gdl::AShader &, gdl::Clock const &);
};

#endif /* !CUBE_HPP_ */
