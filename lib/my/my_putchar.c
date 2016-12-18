/*
** my_putchar.c for my_putchar in /home/Artha77/CPool_Day06/test
**
** Made by dylan renard
** Login   <Artha77@epitech.net>
**
** Started on  Tue Oct 11 18:19:09 2016 dylan renard
** Last update Sun Oct 23 15:02:59 2016 dylan renard
*/

#include <unistd.h>

void	my_putchar(char c)
{
  write(1, &c, 1);
}
