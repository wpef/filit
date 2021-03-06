/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allfortab.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fde-monc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/01/12 15:12:06 by fde-monc          #+#    #+#             */
/*   Updated: 2016/02/02 17:27:39 by fde-monc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

t_tris		**ft_createttris(char *file)
{
	int		fd;
	int		ttris;
	t_tris	**tab;

	ttris = ft_readfile(file);
	if (ttris <= 0)
		return (NULL);
	fd = open(file, O_RDONLY);
	tab = (t_tris **)malloc(sizeof(t_tris *) * ttris + 1);
	tab[ttris] = NULL;
	if (!tab)
		return (NULL);
	tab = ft_filltab(fd, tab);
	close(fd);
	return (tab);
}

t_tris		**ft_filltab(int fd, t_tris **tab)
{
	char	buf[21];
	int		i;

	i = 0;
	while ((read(fd, buf, 21)) > 0)
	{
		buf[20] = '\0';
		tab[i] = ft_makettris(buf);
		tab[i]->ltr = 'A' + i;
		i++;
	}
	close(fd);
	return (tab);
}

t_tris		*ft_makettris(char *buf)
{
	t_tris	*ttris;
	int		line;
	int		i;
	int		j;

	line = 0;
	i = 0;
	j = 0;
	ttris = (t_tris *)malloc(sizeof(t_tris));
	while (buf[i] != '\0' && line < 4)
	{
		if (buf[i] == '#')
		{
			ttris->coord[j][1] = (i % 5) - 1;
			ttris->coord[j][0] = line;
			j++;
		}
		if (buf[i] == '\n')
			line++;
		i++;
	}
	return (ft_replacettris(ttris));
}
