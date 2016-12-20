/*
** verif.c for sokoan in /home/artha/ncruse
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Tue Dec 20 16:27:24 2016 dylan renard
** Last update Tue Dec 20 21:02:50 2016 dylan renard
*/

#include "sokoban.h"
#include <unistd.h>

t_sok			*map_len(char **map)
{
  int			y;
  int			x;
  int			max_x;
  t_sok			*sok;

  if ((sok = malloc(sizeof(t_sok))) == NULL)
    return (NULL);
  y = 0;
  x = 0;
  max_x = 0;
  while (map[y] != NULL)
    {
      max_x = (x > max_x) ? x : max_x;
      x++;
      if (map[y][x] == '\0')
	{
	  x = 0;
	  y++;
	}
    }
  sok->w = max_x;
  sok->h = y - 1;
  return (sok);
}

int			must_resize(t_curse *prog)
{
  struct winsize	ctl;
  t_sok			*sok;
  int			midx;
  int			midy;
  char			*text;

  sok = map_len(prog->map);
  text = "enlarge the terminal please";
  ioctl(STDOUT_FILENO, TIOCGWINSZ, &ctl);
  if (sok->w > ctl.ws_col || sok->h >= ctl.ws_row)
    {
      midx = ctl.ws_col / 2 - my_strlen(text) / 2;
	midy = ctl.ws_row / 2 - 1;
	mvprintw(midy, midx, "%s", text);
	return (0);
    }
  return (1);
}
