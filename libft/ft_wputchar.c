/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_wputchar.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 22:46:01 by plisieck          #+#    #+#             */
/*   Updated: 2015/06/09 22:47:19 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*convertion_base(int base, unsigned long long int nb, char *temp, int s)
{
	long long int t;

	t = nb % base;
	nb /= base;
	if (t > 9)
	{
		temp = (t == 10 && s ? ft_strjoin("A", temp) : ft_strjoin("", temp));
		temp = (t == 11 && s ? ft_strjoin("B", temp) : ft_strjoin("", temp));
		temp = (t == 12 && s ? ft_strjoin("C", temp) : ft_strjoin("", temp));
		temp = (t == 13 && s ? ft_strjoin("D", temp) : ft_strjoin("", temp));
		temp = (t == 14 && s ? ft_strjoin("E", temp) : ft_strjoin("", temp));
		temp = (t == 15 && s ? ft_strjoin("F", temp) : ft_strjoin("", temp));
		temp = (t == 10 && !s ? ft_strjoin("a", temp) : ft_strjoin("", temp));
		temp = (t == 11 && !s ? ft_strjoin("b", temp) : ft_strjoin("", temp));
		temp = (t == 12 && !s ? ft_strjoin("c", temp) : ft_strjoin("", temp));
		temp = (t == 13 && !s ? ft_strjoin("d", temp) : ft_strjoin("", temp));
		temp = (t == 14 && !s ? ft_strjoin("e", temp) : ft_strjoin("", temp));
		temp = (t == 15 && !s ? ft_strjoin("f", temp) : ft_strjoin("", temp));
	}
	else
		temp = ft_strjoin(ft_itoa(t), temp);
	return ((nb > 0 ? convertion_base(base, nb, temp, s) : temp));
}

int		split_wputchar2(wchar_t c, int tab[4])
{
	tab[0] |= 0xC0;
	tab[0] |= (c >> 6);
	tab[1] |= 0x80;
	tab[1] |= (c & 0x3F);
	return (*tab);
}

int		split_wputchar1(wchar_t c, int tab[4])
{
	tab[0] |= 0xE0;
	tab[0] |= (c >> 12);
	tab[1] |= 0x80;
	tab[1] |= ((c >> 6) & 0x3F);
	tab[2] |= 0x80;
	tab[2] |= (c & 0x3F);
	return (*tab);
}

void	split_wputchar(wchar_t c)
{
	int tab[4];

	tab[0] |= 0xF0;
	tab[0] |= (c >> 18);
	tab[1] |= 0x80;
	tab[1] |= ((c >> 12) & 0x3F);
	tab[2] |= 0x80;
	tab[2] |= ((c >> 6) & 0x3F);
	tab[3] |= 0x80;
	tab[3] |= (c & 0x3f);
}

void	ft_wputchar(wchar_t c)
{
	int nb;
	int tab[5];
	int i;

	i = 0;
	tab[0] = 0;
	tab[1] = 0;
	tab[2] = 0;
	tab[3] = 0;
	tab[4] = 0;
	nb = ft_strlen(convertion_base(2, c, "", 0));
	if (nb <= 7)
		tab[0] = (char)c;
	else if (nb <= 11)
		split_wputchar2(c, tab);
	else if (nb <= 16)
		split_wputchar1(c, tab);
	else
		split_wputchar(c);
	while (tab[i])
		write (1, &tab[i++], 1);
}
