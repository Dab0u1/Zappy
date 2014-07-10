//
// GraphEngine.hpp for GraphEngine in /home/vallee_c/Zappy/GraphEngine/src
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Thu Jul  3 14:31:22 2014 david vallee
// Last update Thu Jul 10 11:56:10 2014 david vallee
//

#ifndef GRAPHENGINE_HPP_
# define GRAPHENGINE_HPP_

# include "engine.h"
# include "TextureManager/TextureManager.hpp"
# include "Camera/Camera.hpp"
# include "Primitive/Ground.hpp"
# include "Primitive/Trantorien.hpp"
# include "Primitive/Skybox.hpp"
# include "Primitive/Object.hpp"
# include "../World/World.hpp"

class	graphEngine
{
private:
  gdl::SdlContext	_context;
  gdl::Clock		_clock;
  gdl::Input		_input;
  gdl::BasicShader	_shader;

  World			_world;

  int			_resX;
  int			_resY;
  bool			_fullscreen;

  TextureManager	texManager;
  Camera		camera;
  Skybox		skybox;
  Ground		*ground;
  Trantorien		*pikachu;
  Object		*obj;

public:
  graphEngine(World &, int, int, bool);
  ~graphEngine();
  int		init();
  int		getKey();
  int		draw();

private:
  int		drawMap();
  int		drawPlayers();
};

#endif /* !GRAPHENGINE_HPP_ */
