/*
** Cube.hpp for Cube in /home/vallee_c/BomberMan/EngineTest/MiniEngine/src/Primitive
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Wed May  7 07:49:49 2014 david vallee
// Last update Sat Jul  5 11:56:01 2014 david vallee
*/

#ifndef CUBE_HPP_
# define CUBE_HPP_

# include "../AObject.hpp"
# include "../engine.h"

class	Skybox : public AObject
{
private:
  gdl::Texture *_texture;
  gdl::Geometry _geometry;

public:
  Skybox();
  Skybox(float x, float y, float z);
  Skybox(float x, float y, float z, float size);
  virtual ~Skybox() {}
  virtual void		LoadTexture(gdl::Texture *);
  virtual bool		initialize();
  virtual void		update(gdl::Clock const &, gdl::Input &);
  void		update(gdl::Clock const &, gdl::Input &, glm::vec3 p);
  virtual void		draw(gdl::AShader &, gdl::Clock const &);
};

#endif /* !CUBE_HPP_ */
