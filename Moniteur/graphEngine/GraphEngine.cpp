//
// GraphEngine.cpp for GraphEngine in /home/vallee_c/Zappy/GraphEngine/src
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Thu Jul  3 14:37:59 2014 david vallee
// Last update Sun Jul  6 11:10:12 2014 david vallee
//

#include "GraphEngine.hpp"

#define WINX 1200
#define WINY 800

graphEngine::graphEngine() : test(10, 0.5, 10, 1, 3, 20, 20),
			     skybox(0, 0, 0, 100),
			     obj(5, 0.5, 8, 1, 4)
{
}

graphEngine::graphEngine(World &world) : test(10, 0.5, 10, 1, 3, world.getSizeX(), world.getSizeY()),
			     skybox(0, 0, 0, 500),
			     obj(5, 0.5, 8, 1, 4)
{
  std::cout << world.getSizeX() << " " << world.getSizeY() << std::endl;
  ground = new Ground(0, 0, 0, world.getSizeX(), world.getSizeY());
}

graphEngine::~graphEngine()
{
  delete ground;
}

int	graphEngine::init()
{
  if (!_context.start(WINX, WINY, "Moniteur Graphique Zappy Epitech", SDL_INIT_VIDEO,
  		      SDL_WINDOW_OPENGL))
    return (-1);
  glDisable(GL_DEPTH_TEST);
  glAlphaFunc(GL_GREATER, 0.1f);
  glEnable(GL_ALPHA_TEST);
  glEnable(GL_DEPTH_TEST);
  if (!_shader.load("./shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    return (false);
  texManager.LoadTextureFromFile("texture/texture");
  camera.initialize(WINX, WINY);

  // Initialize
  ground->initialize();
  ground->LoadTexture(texManager.getTexture("ground"));
  test.initialize();
  test.LoadTexture(texManager.getTexture("pika"));
  skybox.initialize();
  skybox.LoadTexture(texManager.getTexture("sky"));
  obj.initialize();
  obj.LoadTexture(texManager.getTexture("obj"));
}

int	graphEngine::getKey()
{  
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  camera.Update(_shader, _clock, _input);
  test.update(_clock, _input, camera.getPosition(), 0.1);
  skybox.update(_clock, _input, camera.getPosition());
  obj.update(_clock, _input, camera.getPosition(), 0.1);
  if (_input.getKey(SDLK_ESCAPE) || _input.getInput(SDL_QUIT))
    return 0;
  return (1);
}

int	graphEngine::draw()
{
  glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
  _shader.bind();
  ground->draw(_shader, _clock);
  test.draw(_shader, _clock);
  skybox.draw(_shader, _clock);
  obj.draw(_shader, _clock);
  _context.flush();
}
