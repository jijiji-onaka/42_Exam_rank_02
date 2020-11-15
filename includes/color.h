/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tjinichi <tjinichi@student.42tokyo.jp>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/11/12 19:57:31 by tjinichi          #+#    #+#             */
/*   Updated: 2020/11/16 04:08:29 by tjinichi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_COLOR_H
# define PRINTF_COLOR_H

# define RESET	"\033[0m"
# define RED	"\033[31m"
# define GREEN	"\033[32m"
# define YELLOW	"\033[33m"
# define BLUE	"\033[34m"
# define MAGENT	"\033[35m"
# define CYAAN	"\033[36m"
# define WHITE	"\033[37m"

int ft_printf(char *str, ...);

#endif
