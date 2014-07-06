//
// GraphEngine.cpp for GraphEngine in /home/vallee_c/Zappy/GraphEngine/src
// 
// Made by david vallee
// Login   <vallee_c@pc-vallee_c>
// 
// Started on  Thu Jul  3 14:37:59 2014 david vallee
// Last update Sun Jul  6 15:46:01 2014 david vallee
//

#include "GraphEngine.hpp"

#define WINX 1200
#define WINY 800

graphEngine::graphEngine() : test(10, 0.5, 10, 1, 3, 20, 20),
			     skybox(0, 0, 0, 100)
{
}

graphEngine::graphEngine(World &world) : test(10, 0.5, 10, 1, 3, world.getSizeX(), world.getSizeY()),
			     skybox(0, 0, 0, 500)
{
  std::cout << world.getSizeX() << " " << world.getSizeY() << std::endl;
  ground = new Ground(0, 0, 0, world.getSizeX(), world.getSizeY());

  obj = new Object*[8];
  obj[0] = new Object(5, 0.5, 8, 1, 1);
  obj[1] = new Object(6, 0.5, 8, 1, 4);
  obj[2] = new Object(7, 0.5, 8, 0.8, 4);
  obj[3] = new Object(8, 0.5, 8, 0.6, 4);
  obj[4] = new Object(9, 0.5, 8, 0.5, 4);
  obj[5] = new Object(10, 0.5, 8, 0.3, 4);
  obj[6] = new Object(11, 0.5, 8, 0.1, 4);
  obj[7] = new Object(12, 0.5, 8, 1, 1);  
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
  if (!_shader.load("./Moniteur/shaders/basic.fp", GL_FRAGMENT_SHADER)
      || !_shader.load("./Moniteur/shaders/basic.vp", GL_VERTEX_SHADER)
      || !_shader.build())
    return (false);
  texManager.LoadTextureFromFile("./Moniteur/texture/texture");
  camera.initialize(WINX, WINY);

  // Initialize
  ground->initialize();
  ground->LoadTexture(texManager.getTexture("ground"));
  test.initialize();
  test.LoadTexture(texManager.getTexture("pika"));
  skybox.initialize();
  skybox.LoadTexture(texManager.getTexture("sky"));

  int	i = 0;
  while (i < 8)
    {
      obj[i]->initialize();
      ++i;
    }
  obj[0]->LoadTexture(texManager.getTexture("food"));
  obj[1]->LoadTexture(texManager.getTexture("linemate"));
  obj[2]->LoadTexture(texManager.getTexture("deraumere"));
  obj[3]->LoadTexture(texManager.getTexture("sibur"));
  obj[4]->LoadTexture(texManager.getTexture("mendiane"));
  obj[5]->LoadTexture(texManager.getTexture("phiras"));
  obj[6]->LoadTexture(texManager.getTexture("thystame"));
  obj[7]->LoadTexture(texManager.getTexture("eggs"));
}

int	graphEngine::getKey()
{  
  _context.updateClock(_clock);
  _context.updateInputs(_input);
  camera.Update(_shader, _clock, _input);
  test.update(_clock, _input, camera.getPosition(), 0.1);
  skybox.update(_clock, _input, camera.getPosition());
  int	i = 0;
  while (i < 8)
    {
      obj[i]->update(_clock, _input, camera.getPosition(), 0.1);
      ++i;
    }
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
  int	i = 0;
  while (i < 8)
    {
      obj[i]->draw(_shader, _clock);
      ++i;
    }
  _context.flush();
}
