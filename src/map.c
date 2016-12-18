/*
** map.c for sokoban in /home/artha/ncruse
**
** Made by dylan renard
** Login   <artha@epitech.net>
**
** Started on  Sun Dec 18 14:09:59 2016 dylan renard
** Last update Sun Dec 18 15:39:38 2016 dylan renard
*/

#include "sokoban.h"

char		*write_buffer(char *name)
{
  int		fd;
  int		ret;
  char		buf[BUFFER_SIZE];

  if ((fd = open(name, O_RDONLY)) == -1)
    return (NULL);
  if ((ret = read(fd, &buf, BUFFER_SIZE)) == 0)
    return (NULL);
  return (my_strdup(buf));
}

int		buf_y_len(char *buf)
{
  int		i;
  int		y;

  i = 0;
  y = 0;
  while (buf[i] != '\0')
    {
      if (buf[i] == '\n')
	y++;
      i++;
    }
  y++;
  return (y);
}

int		buf_x_len(char *buf, int y)
{
  int		i;
  int		x;
  int		dy;

  i = 0;
  x = 0;
  dy = 0;
  while (dy <= y)
    {
      if (dy == y && buf[i] != '\n')
	x++;
      if (buf[i] == '\n' || buf[i] == '\0')
	dy++;
      i++;
    }
  return (x);
}

char		**new_map(char *name, int j, int dy, int i)
{
  char		*buf;
  int		y;
  int		x;
  char		**map;

  if ((buf = write_buffer(name)) == NULL) return (NULL);
  y = buf_y_len(buf);
  if ((map = malloc((y + 1) * sizeof(char *))) == NULL) return (NULL);
  map[y] = NULL;
  while (dy != y)
    {
      x = buf_x_len(buf, dy);
      if ((map[dy] = malloc((x + 1) * sizeof(char))) == NULL) return (NULL);
      while (j != x)
	{
	  map[dy][j] = buf[i + j];
	  j++;
	}
      map[dy][i + x] = '\0';
      i += x + 1;
      j = 0;
      dy++;
    }
  return (map);
}
