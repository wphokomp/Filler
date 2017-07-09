/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 12:48:12 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/05 16:04:37 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

void	ft_freemap(t_env *e)
{
	int		y;

	y = 0;
	while (y < e->map_y)
	{
		free(e->map[y]);
		y++;
	}
	free(e->map);
}

int		ft_allocmap(t_env *e)
{
	char	**line;
	int		y;

	y = 0;
	line = ft_strsplit(ft_until("Plateau"), ' ');
	e->map_y = ft_atoi(line[1]);
	e->map_x = ft_atoi(line[2]);
	if (!(e->map = (char **)malloc(sizeof(char **) * e->map_y)))
		return (0);
	while (y < e->map_y)
	{
		if (!(e->map[y] = (char *)malloc(sizeof(char *) * e->map_x)))
			return (0);
		y++;
	}
	return (1);
}

char	*ft_until(char *str)
{
	char	*line;
	int		found;

	found = 0;
	while (found == 0 && get_next_line(0, &line) != -1)
		if (ft_strstr(line, str) != NULL)
			found = 1;
	return (line);
}

int		main(void)
{
	t_env	e;

	e.turn = 1;
	e.ch = 'O';
	if (ft_strstr(ft_until("$$$"), "p1") == NULL)
	{
		e.turn = 0;
		e.ch = 'X';
	}
	if (ft_allocmap(&e))
		ft_begin(&e);
	return (0);
}
