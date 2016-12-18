/*
** main.c for sokoban in /home/artha/ncruse
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Mon Dec 12 19:28:17 2016 dylan renard
** Last update Sun Dec 18 16:38:18 2016 dylan renard
*/

#include "sokoban.h"

void		init_curse(void)
{
  initscr();
  raw();
  noecho();
  keypad(stdscr, TRUE);
  curs_set(0);
}

t_curse		*start(char *name)
{
  t_curse	*prog;

  if ((prog = malloc(sizeof(t_curse))) ==  NULL)
    return (NULL);
  prog->name = name;
  if ((prog->map = new_map(name, 0, 0, 0)) == NULL)
    return (NULL);
  player_pos_init(prog);
  count_item(prog);
  init_curse();
  return (prog);
}

int		update(t_curse *prog)
{
  int		statut;

  draw_map(prog);
  refresh();
  statut = input_manager(prog);
  if (is_victory(prog))
    return (2);
  else if (is_failure(prog, 0, 0, 0))
    return (3);
  erase();
  return (statut);
}

void		print_msg(void)
{
  my_putstr("USAGE\n");
  my_putstr("\t./my_sokoban map\n\n");
  my_putstr("DESCRIPTION\n");
  my_putstr("\tmap\tfile representing the warehouse map, containing '#' for");
  my_putstr(" walls, 'P' for player, 'X' for boxes and 'O' for storage");
  my_putstr(" location.\n");
}

int		main(int ac, char **av)
{
  int		statut;
  t_curse	*prog;

  if (ac > 1)
    {
      if (my_strcmp(av[1], "-h") == 0)
	return (print_msg(), 0);
      if ((prog = start(av[1])) == NULL)
	return (84);
      statut = 1;
      while (statut)
	{
      statut = update(prog);
      if (statut == 2)
	return (endwin(), 0);
      else if (statut == 3)
	return (endwin(), 1);
    }
      return (0);
    }
    return (84);
}
