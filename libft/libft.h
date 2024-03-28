/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvalerio <mvalerio@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 15:39:06 by mvalerio          #+#    #+#             */
/*   Updated: 2024/03/28 18:10:11 by mvalerio         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include "get_next_line/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>
# include <limits.h>

// Libft
int				ft_atoi(const char *nptr);
void			ft_bzero(void *s, size_t n);
int				ft_isalnum(int c);
int				ft_isalpha(int c);
int				ft_isascii(int c);
int				ft_isdigit(int c);
int				ft_isprint(int c);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t n);
void			*ft_memmove(void *dest, const void *src, size_t n);
void			*ft_memset(void *s, int c, size_t n);
char			*ft_strchr(const char *s, int c);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
size_t			ft_strlcpy(char *dst, const char *src, size_t size);
size_t			ft_strlen(const char *s);
size_t			ft_strlen_until_char(const char *s, char character);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *s1, const char *s2);
char			*ft_strnstr(const char *big, const char *little, size_t len);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
void			*ft_calloc(size_t nmemb, size_t size);
char			*ft_strdup(const char *s);
char			*ft_strndup(const char *s, int max_size);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char *s1, char *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char*));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_remove_string_from_array(char ***array, size_t index);
long			ft_atol(const char *str);

// Libft Bonus

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
	size_t			position;
	size_t			section;
	size_t			up_cost;
	size_t			total_cost;
	size_t			down_cost;
	int				action;
	struct s_list	*tar;
}					t_list;

t_list			*ft_lstnew(void *content);
void			ft_lstadd_front(t_list **lst, t_list *new);
int				ft_lstsize(t_list *lst);
t_list			*ft_lstlast(t_list *lst);
void			ft_lstadd_back(t_list **lst, t_list *new);
void			ft_lstdelone(t_list *lst, void (*del)(void *));
void			ft_lstclear(t_list **lst, void (*del)(void *));
void			ft_lstiter(t_list *lst, void (*f)(void *));
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), \
				void (*del)(void *));

// Printf

void			ft_putnbr_hex_lower_fd(unsigned long n, int fd, int *a);
void			ft_pointer_address(unsigned long n, int fd, int *a);
void			ft_putnbr_hex_upper_fd(unsigned long n, int fd, int *a);
void			ft_putnbr_unsigned_fd(unsigned long n, int fd, int *a);
void			ft_putnbr_printed(int n, int *a);
void			ft_putstr_printed(char *s, int *a);
void			ft_formater(size_t *i, const char *string, \
				int *printed, va_list *list);
int				ft_printf(const char *string, ...);

// Extras

void			ft_free_strarray(char **array);
size_t			ft_arrlen(char **array);

#endif
