/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wphokomp <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/07/05 12:04:17 by wphokomp          #+#    #+#             */
/*   Updated: 2017/07/09 16:40:55 by wphokomp         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "lib/libft.h"

typedef	struct s_env	t_env;

char	*ft_until(char *str);
void	ft_freemap(t_env *e);
void	ft_begin(t_env *e);
int		ft_showmove(int x, int y);
int		ft_makemove(t_env *e);
int		ft_displaymove(t_env *e);

struct	s_env
{
	int		turn;
	char	ch;
	int		map_x;
	int		map_y;
	int		piece_x;
	int		piece_y;
	char	**map;
	char	**piece;
};

#endif
