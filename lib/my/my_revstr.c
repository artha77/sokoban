/*
** my_revstr.c for my_revstr in /home/Artha77/CPool_Day06
**
** Made by dylan renard
** Login   <Artha77@epitech.net>
**
** Started on  Mon Oct 10 07:24:26 2016 dylan renard
** Last update Sun Oct 23 18:36:44 2016 dylan renard
*/

#include "my.h"

char	*my_revstr(char *str)
{
  int	len;
  int	i;
  char	tmp;

  len = my_strlen(str) - 1;
  i = 0;
  while (i < len)
    {
      tmp = *(str + i);
      *(str + i) = *(str + len);
      *(str + len) = tmp;
      len = len - 1;
      i = i + 1;
    }
  return (str);
}
