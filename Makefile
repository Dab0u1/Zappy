##
## Makefile for Makefile_C_template in /home/vallee_c/script
## 
## Made by david vallee
## Login   <vallee_c@epitech.net>
## 
## Started on  Fri Mar 28 17:01:44 2014 david vallee
## Last update Thu Jul 10 17:55:24 2014 gonon_c
##

CC	= cc

RM	= rm -f

SRC_C	= Client/main.c \
	  Client/option.c \
	  Client/start.c \
          Client/cmd_1.c \
          Client/cmd_2.c \
          Client/read_cmd.c \
	  Client/network/connect.c \
	  Client/network/get_msg.c \
	  Client/network/send_msg.c \
	  Client/network/get_next_line.c

SRC_S	= Serveur/main.c \
	  Serveur/serveur.c \
	  Serveur/read_cmd.c \
	  Serveur/add_client.c \
	  Serveur/send_msg.c \
	  Serveur/Exec_cmd/exec_cmd.c \
	  Serveur/Exec_cmd/parsecmd.c \
	  Serveur/Exec_cmd/action1.c \
	  Serveur/Exec_cmd/action2.c \
	  Serveur/Exec_cmd/action3.c \
	  Serveur/Option/option.c \
	  Serveur/Option/team_list.c \
	  Serveur/Option/exec_option.c \
	  Serveur/Init/initServeur.c \
	  Serveur/Init/initGraphMonitor.c \
	  Serveur/Init/initClient.c \
	  Serveur/Cmd/msz.c \
	  Serveur/Cmd/pnw.c \
	  Serveur/Cmd/bct.c \
	  Serveur/Cmd/ppo.c \
	  Serveur/Cmd/sgt.c \
	  Serveur/Cmd/pdi.c \
	  Serveur/Cmd/pin.c \
	  Serveur/Cmd/pbc.c \
	  Serveur/Cmd/inventory.c \
	  Serveur/Cmd/check.c \
	  Serveur/Map/generateMap.c \
	  Serveur/Map/del_elem_in_map.c \
	  Serveur/Map/mapFunct.c \
	  Serveur/MonitorList/monitorList.c

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

re	: fclean $(NAME_C) $(NAME_S)
	  cd Moniteur/; make re; cd ..;

.PHONY	: all clean fclean re
