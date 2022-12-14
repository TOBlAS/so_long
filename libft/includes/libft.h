/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tcaborde <tcaborde@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 13:23:37 by tcaborde          #+#    #+#             */
/*   Updated: 2022/12/09 15:34:32 by tcaborde         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

/*INCLUDES:*/
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <string.h> 

/*STRUCT:*/
typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}	t_list;

/*LISTS*/

void	ft_lstadd_back(t_list **alst, t_list *new);
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstclear(t_list **lst, void (*del)(void*));
void	ft_lstdelone(t_list *lst, void (*del)(void*));
void	ft_lstiter(t_list *lst, void (*f)(void *));
t_list	*ft_lstlast(t_list *lst);
t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list	*ft_lstnew(void *content);
int		ft_lstsize(t_list *lst);

/*MEMORY:*/

void	ft_bzero(void *s, size_t n);
/*The bzero() function erases the data in the n bytes of the memory
       starting at the location pointed to by s, by writing zeros (bytes
       containing '\0') to that area.*/

void	*ft_calloc(size_t count, size_t size);
/*The calloc() function shall allocate unused space for an array of
       count elements each of whose size in bytes is size.  The space
       shall be initialized to all bits 0.*/

void	*ft_memchr(const void *s, int c, size_t n);
/* The memchr() function scans the initial n bytes of the memory
       area pointed to by s for the first instance of c.  Both c and the
       bytes of the memory area pointed to by s are interpreted as
       unsigned char.*/

int		ft_memcmp(const void *s1, const void *s2, size_t n);
/* The memcmp() function compares the first n bytes (each
       interpreted as unsigned char) of the memory areas s1 and s2.*/

void	*ft_memcpy(void *restrict dst, const void *restrict src, size_t n);
/*The memcpy() function copies n bytes from memory area src to
       memory area dest.  The memory areas must not overlap.*/

void	*ft_memmove(void *dst, const void *src, size_t len);
/* The memmove() function copies n bytes from memory area src to
       memory area dest.*/

void	*ft_memset(void *b, int c, size_t len);
/* The memset() function fills the first n bytes of the memory area
       pointed to by s with the constant byte c.*/

/*STRINGS:*/
int		ft_isalnum(int c);
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
void	ft_putchar_fd(char c, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcat(char *restrict dst,
			const char *restrict src, size_t dstsize);
size_t	ft_strlcpy(char *restrict dst,
			const char *restrict src, size_t dstsize);
int		ft_strlen(char *str);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_strtrim(char const *s1, char const *set);
int		ft_tolower(int c);
int		ft_toupper(int c);

char	*ft_substr(char const *s, unsigned int start, size_t len);
/*Returns the substring of the given string at the given start
 position with the given length (or smaller if the length of the original
 string is less than start + length, or length is bigger than MAXSTRINGLEN).*/

char	*ft_strrchr(const char *s, int c);
/*The strrchr() function returns a pointer to the last occurrence of 
	the character c in the string s.*/

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
/*The strnstr() function finds the first occurrence of the substring
       needle in the string haystack, searching until being on n lenght.  
	   The terminating null bytes ('\0')
       are not compared.*/

int		ft_atoi(const char *str);
/*The atoi() function converts the initial portion of the string
       pointed to by str to int.*/

char	*ft_itoa(int n);
/*The itoa() function coverts the integer n into a character string.*/

char	*ft_strchr(const char *s, int c);
/*The strchr() function returns a pointer to the first occurrence
       of the character c in the string s.*/

char	*ft_strdup(const char *s1);
/*The strdup() function returns a pointer to a new string which is
       a duplicate of the string s.*/

#endif