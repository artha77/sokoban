/*
** my_putstr.c for my_putstr in /home/Artha77/CPool_Day04
**
** Made by dylan renard
** Login   <Artha77@epitech.net>
**
** Started on  Thu Oct  6 08:42:57 2016 dylan renard
** Last update Sun Oct 23 15:55:44 2016 dylan renard
*/

#include <unistd.h>
#include "my.h"

int	my_putstr(const char *str)
{
  write(1, str, my_strlen(str));
  return (0);
}
