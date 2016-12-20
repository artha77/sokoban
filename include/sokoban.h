/*
** sokoban.h for sokoban in /home/artha/ncruse
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Dec 18 14:07:32 2016 dylan renard
** Last update Tue Dec 20 20:29:54 2016 dylan renard
*/

#ifndef SOKOBAN_H_
# define SOKOBAN_H_
# define BUFFER_SIZE	4096
#include <stdlib.h>
#include <ncurses.h>
#include <signal.h>
#include <sys/ioctl.h>
#include <fcntl.h>
#include "my.h"

typedef struct		s_curse
{
  int			posx;
  int			posy;
  char			*msg;
  char			**map;
  int			item;
  int			contener;
  int			item_in_contener;
  int			z;
  char			*name;
}			t_curse;

typedef struct		s_sok
{
  int			w;
  int			h;
}			t_sok;

char		**new_map(char *, int, int, int);
void		draw_map(t_curse *);
int		input_manager(t_curse *);
int		is_victory(t_curse *);
int		is_failure(t_curse *, int, int, int);
void		player_pos_init(t_curse *);
void		count_item(t_curse *);
void		swap_case_y(t_curse *, int);
void		swap_case(t_curse *, int);
void		move_y(t_curse *, int);
int		reset(t_curse *);


#endif /* !SOKOBAN_H_ */
