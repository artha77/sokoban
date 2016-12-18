/*
** curse.c for sokoban in /home/artha/ncruse
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Dec 18 14:13:45 2016 dylan renard
** Last update Sun Dec 18 16:52:20 2016 dylan renard
*/

#include "sokoban.h"

void		put_pixel(int x, int y, int color)
{
  start_color();
  init_pair(1, color, COLOR_BLACK);
  attron(A_STANDOUT | COLOR_PAIR(1));
  mvprintw(y, x, " ");
  attroff(A_STANDOUT | COLOR_PAIR(1));
}

void		draw_square(int x, int y, int size)
{
  int		dx;
  int		dy;

  dx = x;
  dy = y;
  while (dy < (y + size))
    {
      dx++;
      put_pixel(dx, dy, COLOR_RED);
      if (dx == (x + size))
	{
	  dx = x;
	  dy++;
	}
    }
}

void		draw_map(t_curse *prog)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (prog->map[i] != NULL)
    {
      if (prog->map[i][j] == '#')
	put_pixel(j, i, COLOR_BLUE);
      else if (prog->map[i][j] == 'P')
	mvprintw(i, j, "P");
      else if (prog->map[i][j] == 'O')
	mvprintw(i, j, "O");
      else if (prog->map[i][j] == 'X')
	mvprintw(i, j, "X");
      else if (prog->map[i][j] == 'Z')
	mvprintw(i, j, "X");
      else if (prog->map[i][j] == 'Q')
	mvprintw(i, j, "P");
      if (prog->map[i][++j] == '\0')
	{
	  i++;
	  j = 0;
	}
    }
}
