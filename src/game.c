/*
** game.c for sokoban in /home/artha/ncruse
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Dec 18 14:23:17 2016 dylan renard
** Last update Tue Dec 20 14:56:27 2016 dylan renard
*/

#include "sokoban.h"

int		is_victory(t_curse *prog)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  prog->z = 0;
  while (prog->map[i] != NULL)
    {
      if (prog->map[i][j] == 'Z')
	(prog->z)++;
      j++;
      if (prog->map[i][j] == '\0')
	{
	  i++;
	  j = 0;
	}
    }
  if (prog->z == prog->contener)
    return (1);
  else
    return (0);
}

int		is_failure(t_curse *prog, int wall, int i, int j)
{
  while (prog->map[i] != NULL)
    {
      if (prog->map[i][j] == 'X')
	{
	  if (prog->map[i][j + 1] == '#')
	    wall++;
	  if (prog->map[i][j - 1] == '#' && prog->map[i][j + 1] != '#')
	    wall++;
	  if (prog->map[i + 1][j] == '#' && prog->map[i - 1][j] != '#')
	    wall++;
	  if (prog->map[i - 1][j] == '#')
	    wall++;
	}
      if (wall >= 2)
	return (1);
      wall = 0;
      j++;
      if (prog->map[i][j] == '\0')
	{
	  i++;
	  j = 0;
	}
    }
  return (0);
}

void		count_item(t_curse *prog)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  prog->contener = 0;
  prog->item = 0;
  while (prog->map[i] != NULL)
    {
      if (prog->map[i][j] == 'O')
	(prog->contener)++;
      else if (prog->map[i][j] == 'X')
	(prog->item)++;
      j++;
      if (prog->map[i][j] == '\0')
	{
	  i++;
	  j = 0;
	}
    }
}

void		player_pos_init(t_curse *prog)
{
  int		i;
  int		j;

  i = 0;
  j = 0;
  while (prog->map[i] != NULL)
    {
      if (prog->map[i][j] == 'P')
	{
	  prog->posx = j;
	  prog->posy = i;
	  break;
	}
      j++;
      if (prog->map[i][j] == '\0')
	{
	  i++;
	  j = 0;
	}
    }
}

int		reset(t_curse *prog)
{
  t_curse	*cpy;

  if ((cpy = malloc(sizeof(t_curse))) ==  NULL)
    return (1);
  if ((cpy->map = new_map(prog->name, 0, 0, 0)) == NULL)
    return (1);
  player_pos_init(cpy);
  count_item(cpy);
  free(prog->map);
  prog->map = cpy->map;
  prog->posx = cpy->posx;
  prog->posy = cpy->posy;
  prog->item = cpy->item;
  prog->contener = cpy->contener;
  return (0);
}
