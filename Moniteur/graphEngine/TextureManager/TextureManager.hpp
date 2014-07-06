/*
** TextureManager.hpp for TextureManager in /home/vallee_c/BomberMan/EngineTest/MiniEngine/src/TextureManager
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Wed May  7 07:50:11 2014 david vallee
// Last update Fri Jul  4 18:23:02 2014 david vallee
*/

#ifndef TEXTUREMANAGER_HPP_
# define TEXTUREMANAGER_HPP_

# include "../engine.h"
# include <map>

class	TextureManager
{
  std::map<std::string , gdl::Texture *> mapTex;
public:
  TextureManager();
  ~TextureManager();
  bool		LoadTextureFromFile(const char *);
  gdl::Texture	*getTexture(std::string);

private:
  bool		LoadTexture(std::string	name, std::string path);
};

#endif /* !TEXTUREMANAGER_HPP_ */
