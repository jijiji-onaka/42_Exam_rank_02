/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/06/22 15:23:39 by tjinichi          #+#    #+#             */
/*   Updated: 2020/11/11 17:57:43 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <limits.h>

typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}				t_list;
size_t			ft_strlen(const char *str);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlcat(char *dst, const char *src, size_t dstsize);
t_list			*ft_lstnew(void *content);
t_list			*ft_lstlast(t_list *lst);
t_list			*ft_lstmap(t_list *lst, void *(*f)(void *), void (*d)(void *));
int				ft_lstsize(t_list *lst);
int				ft_isprint(int c);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isascii(int c);
int				ft_isalnum(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
int				ft_isspace(char str);
int				list_length(t_list *head);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_strcmp(const char *p1, const char *p2);
int				ft_atoi(const char *str);
int				ft_stoi(char *str, int *i);
int				ft_stod(char *str, double *d);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
void			*ft_memccpy(void *dst, const void *src, int c, size_t n);
void			*ft_calloc(size_t count, size_t size);
void			*ft_memcpy(void *dst, const void *src, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memset(void *b, int c, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
void			ft_putendl_fd(char *s, int fd);
void			ft_putnbr_fd(int n, int fd);
void			ft_lstadd_front(t_list **lst, t_list *n);
void			ft_lstadd_back(t_list **lst, t_list *n);
void			ft_lstdelone(t_list *lst, void (*del)(void*));
void			ft_lstclear(t_list **lst, void (*del)(void*));
void			ft_lstiter(t_list *lst, void (*f)(void *));
void			print_list(t_list *head);
char			*ft_strnstr(const char *hay, const char *needle, size_t len);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strdup(const char *s1);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				count_2d(char **ss);
void			*array_free_2d(char ***res, int cur);
long long		ft_numlen(long long n);
int				check_file_tail(char *s, char *tail);
char			*create_file_name(char *directory, char *file, char *extension);
char			*joint_number(char *s, long long num);
long long		file_tail_number(char *s);

#endif
