/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allforgrid.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hponcet <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/12/23 05:04:33 by hponcet           #+#    #+#             */
/*   Updated: 2016/01/08 16:34:57 by hponcet          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int		ft_rootforgrid(t_tris **ttris)
{
	int			nb;

	nb = 0;
	while (ttris[nb] != NULL)
		nb++;
	return (ft_rootsquare(nb * 4));
}

int		ft_checkgridlen(char **grid)
{
	int	i;

	i = 0;
	while (grid[i] != NULL)
		i++;
	return (i);
}

char	**ft_creategrid(int x, int y)
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
		grid[i][j] = '\0';
		i++;
	}
	grid[i] = NULL;
	return (grid);
}

char	**ft_modifgrid(char **grid)
{
	int			i;
	int			j;
	int			count;
	char		**newtab;

	i = 0;
	j = 0;
	count = 0;
	while (grid[i][count])
		count++;
	newtab = ft_creategrid(count + 1, count + 1);
	return (newtab);
}

int		ft_isingrid(char **grid, char ltr)
{
	int			i;
	int			j;

	i = 0;
	while (grid[i] != NULL)
	{
		j = 0;
		while (grid[i][j])
		{
			if (grid[i][j] == ltr)
			{
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}
