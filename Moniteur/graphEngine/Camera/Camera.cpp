/*
** Camera.cpp for Camera in /home/vallee_c/BomberMan/EngineTest/MiniEngine/src/Camera
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Wed May  7 07:49:20 2014 david vallee
// Last update Sun Jul  6 18:30:30 2014 david vallee
*/

#include "Camera.hpp"

#define	PI 3.14

Camera::Camera()
{
  _position = glm::vec3(10, 5, -5);
}

Camera::Camera(float x, float y, float z, int sizeX, int sizeY)
{
  _position = glm::vec3(x, y, z);
  mapX = sizeX;
  mapY = sizeY;
}

bool		Camera::initialize(float _winX, float _winY)
{
  winX = _winX;
  winY = _winY;
  _speed = 20.0f;
  anglX = 1.0;
  anglY = 0;
  projection = glm::perspective(60.0f, winX / winY, 0.1f, 1000.0f);
  return (true);
}

glm::mat4	Camera::getProjection() const
{
  return (projection);
}

glm::mat4	Camera::getTransformation() const
{
  return (transformation);
}

glm::vec3	Camera::getPosition() const
{
  return (_position);
}

void		Camera::translate(glm::vec3 const &v)
{
  _position += v;
}

void		Camera::rotate(glm::vec3 const& axis, float angle)
{
  _rotation += axis * angle;
}

glm::vec3	Camera::getLookat() const
{
  return (_lookat);
}

glm::vec3	Camera::getPos() const
{
  return (_pos);
}

void		Camera::Update(gdl::BasicShader &_shader,
			       gdl::Clock const &clock,
			       gdl::Input &input)
{
  glm::vec3 lastPos;

  lastPos = _position;
  if (input.getKey(SDLK_k))
    translate(glm::vec3(-cos(anglX), -sin(anglY), -sin(anglX))
	      * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_i))
    translate(glm::vec3(cos(anglX), sin(anglY), sin(anglX))
	      * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_l))
    translate(glm::vec3(cos(anglX + 0.5 * PI), 0, sin(anglX + 0.5 * PI))
	      * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_j))
    translate(glm::vec3(-cos(anglX + 0.5 * PI), 0, -sin(anglX + 0.5 * PI))
	      * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_d))
    anglX += 0.05;
  if (input.getKey(SDLK_q))
    anglX -= 0.05;
  if (input.getKey(SDLK_z) && anglY < 2)
    anglY += 0.05;
  if (input.getKey(SDLK_s) && anglY > -2)
    anglY -= 0.05;

  if (input.getKey(SDLK_a))
    translate(glm::vec3(0, 1, 0) * static_cast<float>(clock.getElapsed()) * _speed);
  if (input.getKey(SDLK_e))
    translate(glm::vec3(0, -1, 0) * static_cast<float>(clock.getElapsed()) * _speed);
 
  if (_position.y < 0.2f && _position.y > -3.2f &&
      _position.x - 2.0f < mapX && _position.x > -0.2 &&
      _position.z - 2.0f < mapY && _position.z > -0.2)
    _position = lastPos;
  transformation = glm::lookAt(glm::vec3(_position.x, _position.y, _position.z),
			       glm::vec3(_position.x + 1 * cos(anglX),
					 _position.y + 1 * sin(anglY),
					 _position.z + 1 * sin(anglX)),
			       glm::vec3(0, 2, 0));
  _shader.bind();
  _shader.setUniform("view", getTransformation());
  _shader.setUniform("projection", getProjection());
}
