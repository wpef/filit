/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algogol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 05:04:33 by hponcet           #+#    #+#             */
/*   Updated: 2015/12/23 06:35:51 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "/Includes/fillit.h"

int			ft_rootforgrid(t_tris **ttris)
{
	int		nb;

	nb = 0;
	while (ttris[nb] != NULL)
		nb++;
	return (ft_rootsquare(nb * 4));
}

char		**ft_createormodifgrid(t_tris **ttris, char **grid, int modify)
{
	if (grid == NULL)
		grid = ft_createtab(ft_rootforgrid(ttris), ft_rootforgrid(ttris));
	else
		grid = ft_modiftab(ft_rootforgrid(ttris) + modify, ft_rootforgrid(ttris) + modify);
	return (grid);
}

int			ft_algogol(char **grid, t_tris **ttris)
{
	while (**grid != NULL)
	{
		if (ft_checkttris(grid, *ttris,

	}
}
