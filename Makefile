##
## Makefile for Makefile_C_template in /home/vallee_c/script
## 
## Made by david vallee
## Login   <vallee_c@epitech.net>
## 
## Started on  Fri Mar 28 17:01:44 2014 david vallee
## Last update Sat Jul  5 14:43:22 2014 david vallee
##

CC	= cc

RM	= rm -f

SRC_C	= Client/main.c \
	  Client/start.c \
	  Client/exec_cmd.c \
	  Client/network/connect.c \
	  Client/network/get_msg.c \
	  Client/network/send_msg.c

SRC_S	= Serveur/main.c \
	  Serveur/init.c \
	  Serveur/serveur.c \
	  Serveur/add_client.c \
	  Serveur/send_msg.c

OBJ_C	= $(SRC_C:.c=.o)

OBJ_S	= $(SRC_S:.c=.o)

NAME_C	= client

NAME_S	= serveur

all	: $(NAME_C) $(NAME_S)
	  cd Moniteur/; make; cd ..;

$(NAME_C): $(OBJ_C)
	   $(CC) $(OBJ_C) -o $(NAME_C)

$(NAME_S): $(OBJ_S)
	   $(CC) $(OBJ_S) -o $(NAME_S)

clean	:
	  $(RM) $(OBJ_C)
	  $(RM) $(OBJ_S)
	  cd Moniteur/; make clean; cd ..;

fclean	: clean
	  $(RM) $(NAME_C)
	  $(RM) $(NAME_S)
	  $(RM) moniteur
	  cd Moniteur/; make fclean; cd ..;

re	: fclean all
	  cd Moniteur/; make re; cd ..;

.PHONY	: all clean fclean re
