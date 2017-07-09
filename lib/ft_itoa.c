/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mkgosise <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/06/07 14:28:47 by mkgosise          #+#    #+#             */
/*   Updated: 2017/06/11 03:49:42 by mkgosise         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_itoa(int n)
{
	int		i;
	int		nbr;
	char	*ret;

	i = 0;
	nbr = n;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	ret = (char*)ft_memalloc(i + 1);
	nbr = i;
	while (n != 0)
	{
		i--;
		ret[i] = 48 + (n % 10);
		n = n / 10;
	}
	ret[nbr] = '\0';
	return (ret);
}
