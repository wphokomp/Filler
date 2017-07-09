/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   play2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 13:39:14 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/05 16:41:21 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_getmap(t_env *e)
{
	int		x;
	int		y;
	char	*line;
	char	**table;

	y = 0;
	while (y < e->map_y)
	{
		x = 0;
		get_next_line(0, &line);
		table = ft_strsplit(line, ' ');
		while (x < e->map_x)
		{
			e->map[y][x] = table[1][x];
			x++;
		}
		y++;
	}
}

void	ft_getpiece(t_env *e)
{
	int		x;
	int		y;
	char	*line;

	y = 0;
	while (y < e->piece_y)
	{
		x = 0;
		get_next_line(0, &line);
		while (x < e->piece_x)
		{
			e->piece[y][x] = line[x];
			x++;
		}
		y++;
	}
}

void	ft_piecedel(t_env *e)
{
	int		y;

	y = 0;
	while (y < e->piece_y)
	{
		free(e->piece[y]);
		e->piece[y] = NULL;
		y++;
	}
	//free(e->piece);
	e->piece = NULL;
}

int		ft_allocpiece(t_env *e)
{
	char	**line;
	int		y;

	y = 0;
	line = ft_strsplit(ft_until("Piece"), ' ');
	e->piece_y = ft_atoi(line[1]);
	e->piece_x = ft_atoi(line[2]);
	if (!(e->piece = (char **)malloc(sizeof(char **) * e->piece_y)))
		return (0);
	while (y < e->piece_y)
	{
		if (!(e->piece[y] = (char *)malloc(sizeof(char *) * e->piece_x)))
			return (0);
		y++;
	}
	return (1);
}

void	ft_begin(t_env *e)
{
	if (e->turn)
	{
		ft_until("0123456789");
		ft_getmap(e);
	}
	else
	{
		e->turn = 1;
		ft_until("01234");
		ft_getmap(e);
	}
	ft_allocpiece(e);
	ft_getpiece(e);
	if (!ft_makemove(e))
	{
		ft_showmove(0, 0);
		ft_freemap(e);
		exit(0);
	}
	ft_piecedel(e);
	e->turn = 0;
	ft_until("Plateau");
	ft_begin(e);
}
