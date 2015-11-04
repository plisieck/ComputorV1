/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ftoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 15:35:10 by plisieck          #+#    #+#             */
/*   Updated: 2015/06/05 15:42:58 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_str_size(float n, size_t precision)
{
	int			len;

	len = 0;
	if (n < 0)
	{
		len++;
		n = -n;
	}
	while (n >= 1)
	{
		len++;
		n /= 10;
	}
	if (precision > 0)
		len++;
	len += precision;
	return (len);
}

static void		ft_convert_rest(char *str, float n, size_t prec, int dot)
{
	size_t		i;

	i = 0;
	while (dot--)
	{
		n *= 10;
		*str = (int)n + '0';
		str++;
		n -= (int)n;
	}
	if (prec > 0)
	{
		*str = '.';
		str++;
		while (i++ < prec)
		{
			n *= 10;
			*str = (int)n + '0';
			str++;
			n -= (int)n;
		}
	}
	*str = '\0';
}

static void		ft_convert(char *str, float n, size_t precision)
{
	int			dot;

	dot = 0;
	if (n < 0)
	{
		*str = '-';
		n = -n;
		str++;
	}
	while (n >= 1 && dot++ >= 0)
		n /= 10;
	ft_convert_rest(str, n, precision, dot);
}

char			*ft_ftoa(float n, size_t precision)
{
	char		*str;

	str = NULL;
	str = (char *)malloc(sizeof(*str) * ft_str_size(n, precision) + 1);
	if (str)
		ft_convert(str, n, precision);
	return (str);
}
