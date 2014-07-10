//
// GraphEngine.cpp for GraphEngine in /home/vallee_c/Zappy/GraphEngine/src
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Thu Jul  3 14:37:59 2014 david vallee
// Last update Thu Jul 10 13:35:12 2014 david vallee
//

#include "GraphEngine.hpp"

#define WINX 1200
#define WINY 800

graphEngine::graphEngine(World &world, int resX, int resY, bool fullscreen) :
  camera(10.0, 5.0, 30.0, world.map.getSizeX(), world.map.getSizeY()),
  skybox(0, 0, 0, 500)
{
  _world = world;
  std::cout << world.map.getSizeX() << " " << world.map.getSizeY() << std::endl;
  ground = new Ground(0, 0, 0, world.map.getSizeX(), world.map.getSizeY());
  obj = new Object();
  pikachu = new Trantorien();
  _resX = resX;
  _resY = resY;
  _fullscreen = fullscreen;
}

graphEngine::~graphEngine()
{
  delete ground;
  delete obj;
}

int	graphEngine::init()
{
  int	windowsFlags = SDL_WINDOW_OPENGL;

  if (_fullscreen)
    windowsFlags |= SDL_WINDOW_FULLSCREEN;
  if (!_context.start(_resX, _resY, "Moniteur Graphique Zappy Epitech", SDL_INIT_VIDEO,
  		      windowsFlags))
    return (-1);
  glDisable(GL_DEPTH_TEST);
  glAlphaFunc(GL_GREATER, 0.1f);
  glEnable(GL_ALPHA_TEST);
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./Moniteur/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./Moniteur/shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    return (false);
  texManager.LoadTextureFromFile("./Moniteur/texture/texture");
  camera.initialize(WINX, WINY);

  // Initialize
  ground->initialize();
  ground->LoadTexture(texManager.getTexture("ground"));
  skybox.initialize();
  skybox.LoadTexture(texManager.getTexture("sky"));
  obj->initialize();
  pikachu->initialize();
}

int	graphEngine::getKey()
{  
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  camera.Update(_shader, _clock, _input);
  skybox.update(_clock, _input, camera.getPosition());
  obj->update(_clock, _input, camera.getPosition());
  pikachu->update(_clock, _input, camera.getPosition());
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return 0;
  return (1);
}

int	graphEngine::drawMap()
{
  gdl::Texture	*tex;
  int		x;
  int		y;

  x = 0;
  while (x < _world.map.getSizeX())
    {
      y = 0;
      while (y < _world.map.getSizeY())
	{
	  t_cell *tmp = _world.map.get_cell(x, y);
	  while (tmp)
	    {
	      if (tmp->type == 0)
		tex = texManager.getTexture("food");
	      else if (tmp->type == 1)
		tex = texManager.getTexture("linemate");
	      else if (tmp->type == 2)
		tex = texManager.getTexture("deraumere");
	      else if (tmp->type == 3)
		tex = texManager.getTexture("sibur");
	      else if (tmp->type == 4)
		tex = texManager.getTexture("mendiane");
	      else if (tmp->type == 5)
		tex = texManager.getTexture("phiras");
	      else if (tmp->type == 6)
		tex = texManager.getTexture("thystame");
	      tex->bind();
	      obj->draw(glm::vec3(x + 1.5, 0.2, y + 1.5), _shader, _clock);
	      tmp = tmp->next;
	    }
	  ++y;
	}
      ++x;
    }
}

int	graphEngine::drawPlayers()
{
  gdl::Texture	*tex;
  t_player *tmp;

  tmp = _world.players.getPlayer();
  tex = texManager.getTexture("pika");
  while (tmp)
    {
      tex->bind();
      pikachu->draw(tmp, _shader, _clock);
      tmp = tmp->next;
    }
  return (0);
}

int	graphEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  ground->draw(_shader, _clock);
  skybox.draw(_shader, _clock);
  drawMap();
  drawPlayers();
 _context.flush();
 return (0);
}
