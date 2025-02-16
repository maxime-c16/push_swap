/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcauchy <mcauchy@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 12:45:04 by mcauchy           #+#    #+#             */
/*   Updated: 2025/02/16 12:00:37 by mcauchy          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <strings.h>
# include <stdarg.h>

typedef struct s_list
{
	int				value;
	struct s_list	*next;
}					t_list;

int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_strcmp(char *s1, char *s2);
int		ft_memcmp(const void *s1, const void *s2, int n);
int		ft_strlen(const char *str);
int		ft_atoi(const char *str);
int		ft_isalpha(int c);
int		ft_isalnum(int c);
int		ft_isprint(int c);
int		ft_tolower(int c);
int		ft_isdigit(int c);
int		ft_isascii(int c);
int		ft_toupper(int c);
int		ft_str_is_numeric(char *str);
long	ft_atol(const char *str);
void	*ft_memccpy(void *dest, const void *src, int c, size_t n);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memcpy(void *dst, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, int n);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memset(void *b, int c, size_t len);
void	*ft_calloc(size_t count, size_t size);
void	ft_putendl_fd(char *s, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_bzero(void *b, size_t n);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
char	*ft_strnstr(const char *haystack, const char *needle, size_t n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strjoin_char(char *str, char c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strchr(const char *s, int c);
char	*ft_strdup(const char *s1);
char	*ft_itoa(int n);
char	*ft_strcpy(char *str, char *old_str);
char	**ft_split(char const *s, char c);
size_t	ft_strlcpy(char *dst, const char *src, size_t size);
size_t	ft_strlcat(char *dst, const char *src, size_t size);

// liste chainee

int		ft_lstsize(t_list *lst);
void	ft_lstclear(t_list **alst, void (*del)(int));
void	ft_lstdelone(t_list *lst, void (*del)(int));
void	ft_lstiter(t_list *lst, void (*f)(int));
void	ft_lstadd_front(t_list **alst, t_list *new);
void	ft_lstadd_back(t_list **alst, t_list *new);
t_list	*ft_lstmap(t_list *lst, int (*f)(int), void (*del)(int));
t_list	*ft_lstnew(int content);
t_list	*ft_lstlast(t_list *lst);

int		ft_printf(const char *format, ...);

// utils

int		ft_strlen(const char *str);
int		ft_isdigit(int c);
int		ft_atoi(const char *str);
int		ft_putstr(const char *str);
int		ft_putchar(char c);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int nb);
int		ft_puthex(unsigned long long n, int flag);
int		ft_putptr(void *ptr);

#endif
