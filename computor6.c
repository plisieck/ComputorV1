/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor6.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 15:57:16 by plisieck          #+#    #+#             */
/*   Updated: 2015/06/09 19:10:37 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

float	*get_values(char **tab, int max)
{
	int		i;
	int		j;
	float	*values;

	i = 0;
	j = 0;
	values = (float *)malloc(sizeof(float) * (max + 1));
	values = init_tab(values, max);
	i = 0;
	while (tab[i])
	{
		values[get_power(tab[i])] += get_val(tab[i]);
		i++;
	}
	return (values);
}

float	*sub_tabs(float *left, float *right, int max)
{
	while (max >= 0)
	{
		left[max] = left[max] - right[max];
		max--;
	}
	return (left);
}

char	*treat_natural_shape2(char *str, int *i)
{
	while (str[*i] && ft_isdigit(str[*i]))
		(*i)++;
	if (str[*i] == 'X' || str[*i] == 'x')
	{
		str = ft_insert_str(str, ft_strdup("*"), *i);
		(*i) += 1;
	}
	if (is_sign(str[*i]) || str[*i] == '=' || !str[*i])
	{
		str = ft_insert_str(str, ft_strdup("*X^0"), *i);
		(*i) += 4;
	}
	return (str);
}

char	*treat_natural_shape(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (ft_isdigit(str[i]) && str[i - 1] != '^')
			str = treat_natural_shape2(str, &i);
		if (str[i] == 'X' || str[i] == 'x')
		{
			if (str[i - 1] != '*')
			{
				str = ft_insert_str(str, ft_strdup("1*"), i);
				i += 2;
			}
			if (!str[i + 1] || str[i + 1] != '^')
			{
				str = ft_insert_str(str, ft_strdup("^1"), i + 1);
				i += 3;
			}
		}
		i++;
	}
	return (str);
}

int		get_max(char *str)
{
	int	i;
	int max;

	i = 0;
	max = 0;
	while (str[i])
	{
		if (str[i] == '^')
		{
			if (ft_atoi(&str[i + 1]) > max)
				max = ft_atoi(&str[i + 1]);
		}
		i++;
	}
	return (max);
}
