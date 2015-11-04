/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/05/23 09:29:53 by plisieck          #+#    #+#             */
/*   Updated: 2015/06/05 15:36:22 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	neg(char c)
{
	return (c == '-' ? 1 : 0);
}

float		ft_atof(char *str)
{
	int		ent;
	double	dec;
	float	f;
	int		k;
	int		m;

	ent = 0;
	dec = 0;
	m = 0;
	ent = ft_atoi(str);
	k = (neg(str[0]) ? 0 : 1);
	k += (ent == 0 && neg(str[0]) ? 1 : 0);
	while (ft_isdigit(str[ft_strlen(ft_itoa(ent)) + k + 1 + m]))
		m++;
	if (str[ft_strlen(ft_itoa(ent)) + k] == '.')
		dec = ft_atoi(str + ft_strlen(ft_itoa(ent)) + k + 1);
	if (str[0] == '-')
		f = ent - (dec / ft_power(10, m));
	else
		f = ent + (dec / ft_power(10, m));
	return (f);
}
