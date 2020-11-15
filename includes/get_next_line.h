/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/18 23:15:50 by sehattor          #+#    #+#             */
/*   Updated: 2020/11/11 17:58:01 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdlib.h>
# include <time.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include "./libft.h"
# define NO_RETURN 2
# define R_NL 1
# define R_EOF 0
# define R_ERR -1

typedef struct	s_gnl
{
	int				fd;
	char			*store;
	struct s_gnl	*next;
}				t_gnl;

t_gnl			*gnl_lstnew(char *content, int fd);
void			gnl_lstadd_front(t_gnl **lst, t_gnl *new);
t_gnl			*recognize_fd(int fd, t_gnl **lst);
int				get_next_line(int fd, char **line);

#endif
