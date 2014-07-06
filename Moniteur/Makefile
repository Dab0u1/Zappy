##
## Makefile for Makefile_C_template in /home/vallee_c/script
## 
## Made by david vallee
## Login   <vallee_c@epitech.net>
## 
## Started on  Fri Mar 28 17:01:44 2014 david vallee
## Last update Sun Jul  6 19:50:46 2014 david vallee
##

CXX	= g++

RM	= rm -f

SRC	= graphEngine/GraphEngine.cpp \
	  graphEngine/Camera/Camera.cpp \
	  graphEngine/TextureManager/TextureManager.cpp \
	  graphEngine/Primitive/Ground.cpp \
	  graphEngine/Primitive/Billboard.cpp \
	  graphEngine/Primitive/Skybox.cpp \
	  graphEngine/Primitive/Object.cpp \
	  graphEngine/AObject.cpp \
	  network/connect.cpp \
	  network/get_msg.cpp \
	  network/send_msg.cpp \
	  src/main.cpp \
	  src/load.cpp \
	  src/World.cpp \
	  src/exec_opt.cpp \
	  src/option.cpp

OBJ	= $(SRC:.cpp=.o)
NAME	= moniteur

CXXFLAGS = -I ~/LibBomberman_linux_x64/includes/

all	: $(NAME) $(NAME_EXE)

$(NAME)	: $(OBJ)
	  $(CXX) -o $(NAME) $(OBJ) -L ~/LibBomberman_linux_x64/libs/ -lgdl_gl -lGL -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread -ldl
	  mv $(NAME) ../

clean	:
	  $(RM) $(OBJ)

fclean	: clean
	  $(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
