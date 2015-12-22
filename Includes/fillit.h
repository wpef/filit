/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 17:00:41 by fde-monc          #+#    #+#             */
/*   Updated: 2015/12/22 16:11:55 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>
# include <stdio.h>

typedef struct {
	char	ltr;
	int		coord[4][2];
}			t_tris;

t_tris		**ft_createtab(char *file);
t_tris		*ft_maketris(char *buf);
int			ft_touch(char *buf);
int			ft_isvalid(char *buf);
int			ft_readfile(char *file);

#endif