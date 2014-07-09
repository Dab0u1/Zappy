//
// GraphEngine.hpp for GraphEngine in /home/vallee_c/Zappy/GraphEngine/src
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Thu Jul  3 14:31:22 2014 david vallee
// Last update Tue Jul  8 18:31:50 2014 david vallee
//

#ifndef GRAPHENGINE_HPP_
# define GRAPHENGINE_HPP_

# include "engine.h"
# include "TextureManager/TextureManager.hpp"
# include "Camera/Camera.hpp"
# include "Primitive/Ground.hpp"
# include "Primitive/Billboard.hpp"
# include "Primitive/Skybox.hpp"
# include "Primitive/Object.hpp"
# include "../World/World.hpp"

class	graphEngine
{
private:
  World			_world;
  gdl::SdlContext	_context;
  gdl::Clock		_clock;
  gdl::Input		_input;
  gdl::BasicShader	_shader;

  int			_resX;
  int			_resY;
  bool			_fullscreen;

  TextureManager	texManager;
  Camera		camera;
  Ground		*ground;
  Skybox		skybox;
  Billboard		test;
  Object		*obj;

public:
  graphEngine(World &, int, int, bool);
  ~graphEngine();
  int		init();
  int		getKey();
  int		draw();
};

#endif /* !GRAPHENGINE_HPP_ */
