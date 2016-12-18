/*
** my.h for  in /home/Artha77/CPool_infinadd/src
**
** Made by dylan renard
** Login   <Artha77@epitech.net>
**
** Started on  Sun Oct 23 15:02:00 2016 dylan renard
** Last update Sun Nov 27 10:38:32 2016 dylan renard
*/


#ifndef MY_H_
# define MY_H_

void	my_putchar(char c);
int	my_putstr(const char *str);
int	my_strlen(const char *str);
char	*my_strcpy(char *dest, const char *src);
int	my_str_isnum(const char *str);
int	is_bt(char c, char a, char b);
char	*my_strdup(const char *str);
void	my_puterr(const char *s);
char	*my_revstr(char *str);
int	my_strcmp(char *s1, char *s2);
int	my_put_nbr(int);

#endif /* !MY_H_ */
