/*
** my_strcmp.c for my_strcmp in /home/Artha77/CPool_Day06/test
**
** Made by dylan renard
** Login   <Artha77@epitech.net>
**
** Started on  Tue Oct 11 17:52:12 2016 dylan renard
** Last update Sun Oct 23 20:02:57 2016 dylan renard
*/

int	my_strcmp(char *s1, char *s2)
{
  int	i;

  i = 0;
  while (*(s1 + i) != '\0' && *(s1 + i) == *(s2 + i))
    i = i + 1;
  if (*(s1 + i) > *(s2 + i))
    return (1);
  else if (*(s1 + i) < *(s2 + i))
    return (-1);
  return (0);
}
