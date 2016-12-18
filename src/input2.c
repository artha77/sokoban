/*
** input2.c for sokoban in /home/artha/ncruse
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Dec 18 14:06:09 2016 dylan renard
** Last update Sun Dec 18 16:08:53 2016 dylan renard
*/

#include "sokoban.h"

void		swap_case(t_curse *prog, int x)
{
  if (prog->map[prog->posy][prog->posx] == 'P')
    {
      prog->map[prog->posy][prog->posx + x] = 'P';
      prog->map[prog->posy][prog->posx] = ' ';
    }
  else
    {
      prog->map[prog->posy][prog->posx] = 'O';
      prog->map[prog->posy][prog->posx + x] = 'P';
    }
prog->posx += x;
}

void		move_y_item(t_curse *prog, int y)
{
  if (prog->map[prog->posy + (y * 2)][prog->posx] != '#' &&
      prog->map[prog->posy + (y * 2)][prog->posx] != 'X' &&
      prog->map[prog->posy + (y * 2)][prog->posx] != 'Z')
    {
      if (prog->map[prog->posy + (y * 2)][prog->posx] == 'O')
	{
	  prog->map[prog->posy][prog->posx] = ' ';
	  prog->map[prog->posy + y][prog->posx] = 'P';
	  prog->map[prog->posy + (y * 2)][prog->posx] = 'Z';
	}
      else
	{
	  if (prog->map[prog->posy][prog->posx] == 'Q')
	    prog->map[prog->posy][prog->posx] = 'O' ;
	  else
	    prog->map[prog->posy][prog->posx] = ' ';
	  prog->map[prog->posy + y][prog->posx] = 'P';
	  prog->map[prog->posy + (y * 2)][prog->posx] = 'X';
	}
      prog->posy += y;
    }
}

void		move_y_on_contener(t_curse* prog, int y)
{
  prog->map[prog->posy + y][prog->posx] = 'Q';
  prog->map[prog->posy][prog->posx] = ' ';
  prog->posy += y;
}

void		move_y_item_on_contener(t_curse *prog, int y)
{
  if (prog->map[prog->posy + (y * 2)][prog->posx] != '#' &&
      prog->map[prog->posy + (y * 2)][prog->posx] != 'X' &&
      prog->map[prog->posy + (y * 2)][prog->posx] != 'Z')
    {
      if (prog->map[prog->posy + (y * 2)][prog->posx] == 'O')
	{
	  prog->map[prog->posy][prog->posx] = ' ';
	  prog->map[prog->posy + y][prog->posx] = 'Q';
	  prog->map[prog->posy + (y * 2)][prog->posx] = 'Z';
	}
      else
	{
	  if (prog->map[prog->posy][prog->posx] == 'Q')
	    prog->map[prog->posy][prog->posx] = 'O' ;
	  else
	    prog->map[prog->posy][prog->posx] = ' ';
	  prog->map[prog->posy + y][prog->posx] = 'Q';
	  prog->map[prog->posy + (y * 2)][prog->posx] = 'X';
	}
      prog->posy += y;
    }
}

void		move_y(t_curse *prog, int y)
{
  if (prog->map[prog->posy + y][prog->posx] != '#')
    {
      if (prog->map[prog->posy + y][prog->posx] == 'X')
	move_y_item(prog, y);
      else if (prog->map[prog->posy + y][prog->posx] == ' ')
	swap_case_y(prog, y);
      else if (prog->map[prog->posy + y][prog->posx] == 'O')
	move_y_on_contener(prog, y);
      else if (prog->map[prog->posy + y][prog->posx] == 'Z')
	move_y_item_on_contener(prog, y);
    }
}
