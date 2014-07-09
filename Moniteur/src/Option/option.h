/*
** tcp-ip.h for ZAP in /home/gonon_c/rendu/Zappy/Moniteur/src
** 
** Made by gonon_c
** Login   <gonon_c@epitech.net>
** 
** Started on  Sun Jul  6 18:21:39 2014 gonon_c
** Last update Sun Jul  6 19:22:56 2014 gonon_c
*/

#ifndef CLIENT_H_
# define CLIENT_H_

typedef struct	s_option
{
  char		*ip;
  int		port;
  int		x;
  int		y;
  bool		fullscreen;
}		t_option;

int		opt_p(t_option *option, char **av, int *j);
int		opt_h(t_option *option, char **av, int *j);
int		opt_x(t_option *option, char **av, int *j);
int		opt_y(t_option *option, char **av, int *j);
int		opt_f(t_option *option, char **av, int *j);
int             find_opt(char *buf);
int             print_rules(int *cool);
int             exec_opt(t_option *option, int ac, char **av);
int		default_value(t_option *option);

#endif /* !CLIENT_H_ */
