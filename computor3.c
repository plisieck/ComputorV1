/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 15:48:35 by plisieck          #+#    #+#             */
/*   Updated: 2015/06/05 15:50:51 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int		count_parts(char *str)
{
	int	i;
	int	nb;

	i = 0;
	nb = 0;
	while (str[i])
	{
		nb++;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] && str[i] != '-' && str[i] != '+')
			i++;
	}
	return (nb);
}

char	**split_str(char *str)
{
	int		i;
	int		j;
	int		k;
	char	**tab;

	i = 0;
	k = 0;
	tab = (char **)malloc(sizeof(char *) * (count_parts(str) + 1));
	while (str[i])
	{
		j = i;
		if (str[i] == '-' || str[i] == '+')
			i++;
		while (str[i] && str[i] != '-' && str[i] != '+')
			i++;
		tab[k++] = ft_strsub(str, j, i - j);
	}
	tab[k] = 0;
	return (tab);
}

int		get_degree(char **tab)
{
	int	i;
	int	max;

	i = 0;
	max = 0;
	while (tab[i])
	{
		if (get_power(tab[i]) > max)
			max = get_power(tab[i]);
		i++;
	}
	return (max);
}

char	*get_reduced_form2(float *tab, char *str, int i)
{
	if (tab[i] < 0)
	{
		if (i != 0)
			str = ft_strjoin(str, " ");
		str = ft_strjoin(str, "- ");
	}
	else if (i != 0)
		str = ft_strjoin(str, " + ");
	return (str);
}

char	*get_reduced_form(float *tab, int max)
{
	int		i;
	char	*str;

	i = 0;
	str = NULL;
	while (i <= max)
	{
		if (ft_strcmp(print_float(tab[i]), "0"))
		{
			str = get_reduced_form2(tab, str, i);
			if (tab[i] < 0)
				str = ft_strjoin(str, print_float(-tab[i]));
			else
				str = ft_strjoin(str, print_float(tab[i]));
			str = ft_strjoin(ft_strjoin(str, " * X^"), ft_itoa(i));
		}
		i++;
	}
	if (!str)
		return ("0");
	return (str);
}
