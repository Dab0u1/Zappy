##
## Makefile for Makefile_C_template in /home/vallee_c/script
## 
## Made by david vallee
## Login   <vallee_c@epitech.net>
## 
## Started on  Fri Mar 28 17:01:44 2014 david vallee
## Last update Sat Jul  5 13:29:38 2014 david vallee
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
	  src/main.cpp

OBJ	= $(SRC:.cpp=.o)
NAME	= moniteur

CXXFLAGS = -I ~/LibBomberman_linux_x64/includes/

all	: $(NAME) $(NAME_EXE)

$(NAME)	: $(OBJ)
	  $(CXX) -o $(NAME) $(OBJ) -L ~/LibBomberman_linux_x64/libs/ -lgdl_gl -lGL -lGLEW -lrt -lfbxsdk -lSDL2 -lpthread -ldl
clean	:
	  $(RM) $(OBJ)

fclean	: clean
	  $(RM) $(NAME)

re	: fclean all

.PHONY	: all clean fclean re
