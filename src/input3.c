/*
** input3.c for sokoban in /home/artha/ncruse
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Dec 18 15:11:43 2016 dylan renard
** Last update Sun Dec 18 15:16:00 2016 dylan renard
*/

#include "sokoban.h"

void		swap_case_y(t_curse *prog, int y)
{
  if (prog->map[prog->posy][prog->posx] == 'P')
    {
      prog->map[prog->posy + y][prog->posx] = 'P';
      prog->map[prog->posy][prog->posx] = ' ';
    }
  else
    {
      prog->map[prog->posy][prog->posx] = 'O';
      prog->map[prog->posy + y][prog->posx] = 'P';
    }
prog->posy += y;
}
