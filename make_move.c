/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_move2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 14:09:18 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/05 16:09:05 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

int		ft_checkpiece(t_env *e, int y_a, int x_a)
{
	int		meet;
	int		x;
	int		y;
	int		x_b;

	y = 0;
	meet = 0;
	while (y < e->piece_y && y_a < e->map_y)
	{
		x = 0;
		x_b = x_a;
		while (x < e->piece_y && x_b < e->map_x)
		{
			if (e->piece[y][x] == '*' && e->map[y_a][x_a] != '.')
				meet++;
			if (meet == 2)
				return (0);
			x++;
			x_a++;
		}
		y++;
		y_a++;
	}
	return (1);
}

int		ft_showmove(int x, int y)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
	return (1);
}

int		ft_putpiece(t_env *e, int x_a, int y_a)
{
	int		x;
	int		y;
	int		x_b;
	int		y_b;

	y = 0;
	while (y < e->piece_y)
	{
		x = 0;
		while (x < e->piece_x)
		{
			if (e->piece[y][x] == '*')
			{
				x_b = x_a - x;
				y_b = y_a - y;
				if (x_b >= 0 && y_b >= 0 &&
						(x_b + e->piece_x - 1) < e->map_x && (y_b + e->piece_y
							- 1) < e->map_y && ft_checkpiece(e, y_b, x_b))
					return (ft_showmove(y_a - y, x_a - x));
			}
			x++;
		}
		y++;
	}
	return (0);
}

int		ft_makemove(t_env *e)
{
	int		x;
	int		y;

	y = 0;
	while (y < e->map_y)
	{
		x = 0;
		while (x < e->map_x)
		{
			if (e->map[y][x] == e->ch)
				if (ft_putpiece(e, y, x))
					return (1);
			x++;
		}
		y++;
	}
	return (0);
}
