##
## Makefile for Makefile_C_template in /home/vallee_c/script
## 
## Made by david vallee
## Login   <vallee_c@epitech.net>
## 
## Started on  Fri Mar 28 17:01:44 2014 david vallee
## Last update Wed Jul  9 00:09:20 2014 david vallee
##

CXX	= g++

RM	= rm -f

SRC	= src/graphEngine/GraphEngine.cpp \
	  src/graphEngine/Camera/Camera.cpp \
	  src/graphEngine/TextureManager/TextureManager.cpp \
	  src/graphEngine/Primitive/Ground.cpp \
	  src/graphEngine/Primitive/Billboard.cpp \
	  src/graphEngine/Primitive/Skybox.cpp \
	  src/graphEngine/Primitive/Object.cpp \
	  src/graphEngine/AObject.cpp \
	  src/network/connect.cpp \
	  src/network/get_msg.cpp \
	  src/network/send_msg.cpp \
	  src/main.cpp \
	  src/World/World.cpp \
	  src/Option/exec_opt.cpp \
	  src/Option/option.cpp \
	  src/Map/Map.cpp

OBJ	= $(SRC:.cpp=.o)
NAME	= moniteur

CXXFLAGS = -I ../lib/LibBomberman_linux_x64/includes/

all	: $(NAME) $(NAME_EXE)

$(NAME)	: $(OBJ)
	  $(CXX) -o $(NAME) $(OBJ) -L ../lib/LibBomberman_linux_x64/libs/ -lgdl_gl -lGL -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread -ldl
	  mv $(NAME) ../

clean	:
	  $(RM) $(OBJ)

fclean	: clean
	  $(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
