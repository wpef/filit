/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/21 17:00:41 by fde-monc          #+#    #+#             */
/*   Updated: 2016/01/18 16:10:29 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft.h"
# include <fcntl.h>

typedef struct {
	char	ltr;
	int		coord[4][2];
}			t_tris;

t_tris		**ft_createttris(char *file);
t_tris		*ft_makettris(char *buf);
int			ft_touch(char *buf);
int			ft_isvalid(char *buf);
int			ft_readfile(char *file);
int			ft_checkttris(char **grid, t_tris *ttris, int gx, int gy);
char		**ft_writettris(char **grid, t_tris *ttris, int gx, int gy);
char		**ft_deletettris(char **grid, t_tris *ttris);
int			ft_rootforgrid(t_tris **ttris);
char		**ft_modifgrid(char **grid);
char		**ft_creategrid(int x, int y);
t_tris		*ft_replacettris(t_tris *ttris);
int			ft_fillit(char **grid, t_tris **ttris, int x, int y);
int			*ft_whereisttris(char **grid, t_tris **trtis);
int			ft_checkgridlen(char **grid);
int			ft_isingrid (char **grid, char ltr);
void		ft_printgrid(char **grid);
t_tris		**ft_filltab(int fd, t_tris **tab);
int			ft_block(char *buf);

#endif
