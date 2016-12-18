/*
** my_strlen.c for my_strlen in /home/Artha77/CPool_Day04
**
** Made by dylan renard
** Login   <Artha77@epitech.net>
**
** Started on  Thu Oct  6 08:59:36 2016 dylan renard
** Last update Sun Oct 23 15:30:19 2016 dylan renard
*/

int	my_strlen(const char *str)
{
  int	i;

  i = 0;
  while (str && str[i])
    i++;
  return (i);
}
