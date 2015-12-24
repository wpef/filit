/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_algogol.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 05:04:33 by hponcet           #+#    #+#             */
/*   Updated: 2015/12/24 12:31:45 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "fillit.h"

int			ft_rootforgrid(t_tris **ttris)
{
	int		nb;

	nb = 0;
	while (ttris[nb] != NULL)
		nb++;
	return (ft_rootsquare(nb * 4));
}
char		**ft_creategrid(int x, int y)
{
	char		**grid;
	int			i;
	int			j;

	i = 0;
	grid = ft_createtab(x, y);
	while (grid[i] != NULL)
	{
		j = 0;
		while (j < x)
		{
			grid[i][j] = '.';
			j++;
		}
		i++;
	}
	return (grid);
}

char		**ft_modifgrid(char **grid)
{
	int		i;

	i = 0;
	while (grid[i] != NULL)
		i++;
	grid = ft_modiftab(grid, i + 1, i + 1);
	return (grid);
}
