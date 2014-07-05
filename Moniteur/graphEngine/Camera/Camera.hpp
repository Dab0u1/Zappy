/*
** Camera.hpp for Camera in /home/vallee_c/BomberMan/EngineTest/MiniEngine/src/Camera
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Wed May  7 07:49:05 2014 david vallee
// Last update Fri Jul  4 18:47:02 2014 david vallee
*/

#ifndef CAMERA_HPP_
# define CAMERA_HPP_

# include "../engine.h"

class	Camera
{
private:
  glm::mat4	projection;
  glm::mat4	transformation;
  float		_speed;
  glm::vec3	_position;
  glm::vec3	_rotation;
  glm::vec3	_scale;
  float		anglX;
  float		anglY;
  float		winX;
  float		winY;

  glm::vec3	_lookat;
  glm::vec3	_pos;

public:
  Camera();
  Camera(float x, float y, float z);
  ~Camera() {}

  bool		initialize(float, float);
  glm::mat4	getProjection() const;
  glm::mat4	getTransformation() const;
  glm::vec3	getPosition() const;

  glm::vec3	getLookat() const;
  glm::vec3	getPos() const;

  void		Update(gdl::BasicShader &, gdl::Clock const &, gdl::Input &);
  void		translate(glm::vec3 const &v);
  void		rotate(glm::vec3 const&, float);
};

#endif /* !CAMERA_HPP_ */
