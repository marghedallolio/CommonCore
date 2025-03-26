/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: npezzati <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/25 17:44:47 by npezzati          #+#    #+#             */
/*   Updated: 2024/11/25 17:46:19 by npezzati         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h> 
# include <stdlib.h>
# include <stdio.h>
# include <stdarg.h>
//# include <string.h>

typedef struct s_nodo
{
	int				value;
	int				index;
	struct s_nodo	*next;
}	t_node;

void	*ft_memset(void *s, int c, size_t n);
void	ft_bzero(void *s, size_t n);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	*ft_memchr(const void *s, int c, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
void	ft_putnbr_fd(int n, int fd);
//void	ft_lstadd_front(t_node **lst, t_node *new);
//void	ft_lstadd_back(t_node **lst, t_node *new);
//void	ft_lstdelone(t_node *lst, void (*del)(void *));
//void	ft_lstclear(t_node **lst, void (*del)(void *));
//void	ft_lstiter(t_node *lst, void (*f)(void *));
int		ft_isalpha(int c);
int		ft_isdigit(int c);
int		ft_isalnum(int c);
int		ft_isascii(int c);
int		ft_isprint(int c);
int		ft_toupper(int c);
int		ft_tolower(int c);
int		ft_lstsize(t_node *lst);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
int		ft_memcmp(const void *s1, const void *s2, size_t n);
int		ft_atoi(const char *nptr);
size_t	ft_strlcat(char *dst, const char *src, size_t size);
size_t	ft_strlen(const char *s);
size_t	ft_strlcpy(char *dst, char *src, size_t size);
char	*ft_strchr(const char *s, int c);
char	*ft_strrchr(const char *s, int c);
char	*ft_strnstr(const char *big, const char *little, size_t len);
char	*ft_strdup(const char *s);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strtrim(char const *s1, char const *set);
char	*ft_itoa(int n);
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char));
char	**ft_split(char const *s, char c);
//t_node	*ft_lstnew(void *content);
//t_node	*ft_lstlast(t_node *lst);
//t_node	*ft_lstmap(t_node *lst, void *(*f)(void *), void (*del)(void *));
int		ft_printf(const char *format, ...);
int		ft_putchar(char c);
int		ft_putstr(const char *str);
int		ft_putptr(void *ptr);
int		ft_putnbr(int n);
int		ft_putunsigned(unsigned int n);
int		ft_puthex(unsigned long n, int upp);

#endif
