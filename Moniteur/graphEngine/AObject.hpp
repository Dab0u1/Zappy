/*
** AObject.hpp for AObject in /home/vallee_c/BomberMan/test4
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Mon May  5 18:42:13 2014 david vallee
// Last update Fri Jul  4 18:29:31 2014 david vallee
*/

#ifndef AOBJECT_HPP_
# define AOBJECT_HPP_

# include <OpenGL.hh>
# include <SdlContext.hh>
# include <Clock.hh>
# include <Input.hh>
# include <Geometry.hh>
# include <Texture.hh>
# include <glm/glm.hpp>
# include <glm/gtc/matrix_transform.hpp>

class AObject
{
 protected:
  glm::vec3	_position;
  glm::vec3	_rotation;
  glm::vec3	_scale;

 public:
  AObject();
  AObject(float x, float y, float z);
  AObject(float x, float y, float z, float size);  
  AObject(glm::vec3 const &v);
  AObject(glm::vec3 const &, glm::vec3 const &, glm::vec3 const &);

  virtual	~AObject();

  virtual bool	initialize() = 0;
  virtual void	LoadTexture(gdl::Texture *texture) = 0;
  virtual void	update(gdl::Clock const &clock, gdl::Input &input) = 0;
  virtual void	draw(gdl::AShader &shader, gdl::Clock const &clock) = 0;
  
  glm::vec3	getPosition();
  void		translate(glm::vec3 const &v);
  void		rotate(glm::vec3 const& axis, float angle);
  void		scale(glm::vec3 const& scale);
  glm::mat4	getTransformation();  
};

#endif /* !AOBJECT_HPP_ */
