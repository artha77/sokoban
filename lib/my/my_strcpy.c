/*
** my_strcpy.c for my_strcpy in /home/Artha77/CPool_Day06
**
** Made by dylan renard
** Login   <Artha77@epitech.net>
**
** Started on  Mon Oct 10 07:07:31 2016 dylan renard
** Last update Sun Oct 23 15:57:21 2016 dylan renard
*/

char	*my_strcpy(char *dest, const char *src)
{
  int	i;

  i = 0;
  while (*(src + i) != '\0')
    {
      *(dest + i) = *(src + i);
      i = i + 1;
    }
  *(dest + i) = '\0';
  return (dest);
}
