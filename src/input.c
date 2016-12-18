/*
** input.c for sokoban in /home/artha/ncruse
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Dec 18 14:04:23 2016 dylan renard
** Last update Sun Dec 18 17:02:58 2016 dylan renard
*/

#include "sokoban.h"

void		move_x_item(t_curse *prog, int x)
{
  if (prog->map[prog->posy][prog->posx + (x * 2)] != '#' &&
      prog->map[prog->posy][prog->posx + (x * 2)] != 'X' &&
      prog->map[prog->posy][prog->posx + (x * 2)] != 'Z')
    {
      if (prog->map[prog->posy][prog->posx + (x * 2)] == 'O')
	{
	  prog->map[prog->posy][prog->posx] = ' ';
	  prog->map[prog->posy][prog->posx + x] = 'P';
	  prog->map[prog->posy][prog->posx + (x * 2)] = 'Z';
	}
      else
	{
	  if (prog->map[prog->posy][prog->posx] == 'Q')
	    prog->map[prog->posy][prog->posx] = 'O' ;
	  else
	    prog->map[prog->posy][prog->posx] = ' ';
	  prog->map[prog->posy][prog->posx + x] = 'P';
	  prog->map[prog->posy][prog->posx + (x * 2)] = 'X';
	}
      prog->posx += x;
    }
}

void		move_x_on_contener(t_curse* prog, int x)
{
  prog->map[prog->posy][prog->posx + x] = 'Q';
  prog->map[prog->posy][prog->posx] = ' ';
  prog->posx += x;
}

void		move_x_item_on_contener(t_curse *prog, int x)
{
  if (prog->map[prog->posy][prog->posx + (x * 2)] != '#' &&
      prog->map[prog->posy][prog->posx + (x * 2)] != 'X' &&
      prog->map[prog->posy][prog->posx + (x * 2)] != 'Z')
    {
      if (prog->map[prog->posy][prog->posx + (x * 2)] == 'O')
	{
	  prog->map[prog->posy][prog->posx] = ' ';
	  prog->map[prog->posy][prog->posx + x] = 'Q';
	  prog->map[prog->posy][prog->posx + (x * 2)] = 'Z';
	}
      else
	{
	  if (prog->map[prog->posy][prog->posx] == 'Q')
	    prog->map[prog->posy][prog->posx] = 'O' ;
	  else
	    prog->map[prog->posy][prog->posx] = ' ';
	  prog->map[prog->posy][prog->posx + x] = 'Q';
	  prog->map[prog->posy][prog->posx + (x * 2)] = 'X';
	}
      prog->posx += x;
    }
}

void		move_x(t_curse *prog, int x)
{
  if (prog->map[prog->posy][prog->posx + x] != '#')
    {
      if (prog->map[prog->posy][prog->posx + x] == 'X')
	move_x_item(prog, x);
      else if (prog->map[prog->posy][prog->posx + x] == ' ')
	swap_case(prog, x);
      else if (prog->map[prog->posy][prog->posx + x] == 'O')
	move_x_on_contener(prog, x);
      else if (prog->map[prog->posy][prog->posx + x] == 'Z')
	move_x_item_on_contener(prog, x);
    }
}

int		input_manager(t_curse *prog)
{
  int		input;

  input = getch();
  if (input == 'q')
    {
      endwin();
      return (0);
    }
  else if (input == KEY_UP)
    move_y(prog, -1);
  else if (input == KEY_LEFT)
    move_x(prog, -1);
  else if (input == KEY_RIGHT)
    move_x(prog, 1);
  else if (input == KEY_DOWN)
    move_y(prog, 1);
  else if (input == ' ')
    {
      if (reset(prog))
	return (endwin(), 0);
    }
  return (1);
}
