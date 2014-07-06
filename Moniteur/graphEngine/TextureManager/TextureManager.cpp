/*
** TextureManager.cpp for TextureManager in /home/vallee_c/BomberMan/EngineTest/MiniEngine/src/TextureManager
** 
** Made by david vallee
** Login   <vallee_c@pc-vallee_c>
** 
** Started on  Wed May  7 07:50:04 2014 david vallee
// Last update Mon May 12 16:17:16 2014 david vallee
*/



#include <fstream>
#include <sstream>
#include "TextureManager.hpp"

TextureManager::TextureManager()
{
}

TextureManager::~TextureManager()
{
  // std::map<std::string , gdl::Texture *>::iterator it;
  // for (it = mapTex.begin(); it!=mapTex.end(); ++it)
  //   delete ;
}

bool		TextureManager::LoadTextureFromFile(const char *file)
{
  std::ifstream	txt(file);
  std::string	line;
  std::string	name;
  std::string	path;

  while (getline(txt, line))
    {
      std::istringstream	ss(line);
      getline(ss, name, ':');
      getline(ss, path, '\n');
      LoadTexture(name, path);
    }
  return (true);
}

bool		TextureManager::LoadTexture(std::string	name, std::string path)
{  
  gdl::Texture	*newTex;
    
  newTex = new gdl::Texture();
  if (newTex->load(path) == false)
    {
      std::cerr << "Cannot load : " << path << " for " << name << std::endl;
      return (false);
    }
  else
    std::cout << "Loading : " << path << std::endl;
  mapTex.insert(std::pair<std::string , gdl::Texture *>(name, newTex));
  return (true);
}

gdl::Texture	*TextureManager::getTexture(std::string str)
{
  return (mapTex[str]);
}

