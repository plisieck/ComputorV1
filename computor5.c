/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor5.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 15:54:57 by plisieck          #+#    #+#             */
/*   Updated: 2015/06/12 15:51:28 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	print_result(float *tab, int max)
{
	char	**tmp;
	int		degree;
	char	*reduced_form;

	reduced_form = get_reduced_form(tab, max);
	ft_putstr("\033[4mReduced form:\033[0;0m");
	ft_putendl(ft_strjoin(" ", ft_strjoin(reduced_form, " = 0")));
	tmp = split_str(reduced_form);
	degree = get_degree(tmp);
	ft_putendl(ft_strjoin("Polynomial degree: ", ft_itoa(degree)));
	if (!ft_strcmp(reduced_form, "0"))
		ft_putendl("\033[32mAll real numbers are solution.");
	else if (!check_all_tab(tab, max))
	{
		ft_putendl("\033[31mThere is no solution.");
		return ;
	}
	else if (degree > 2)
		print_error(3);
	else if (degree == 0 || degree == 1)
		print_result3(tab, degree);
	else if (degree >= 2)
		print_result4(tab);
	do_mlx(tab);
}

int		ft_tablen(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
		i++;
	return (i);
}

float	find_val(char **tab, int power)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (get_power(tab[i]) == power)
			return (get_val(tab[i]));
		i++;
	}
	return (0);
}

int		power_exist(char **tab, int power)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		if (get_power(tab[i]) == power)
			return (1);
		i++;
	}
	return (0);
}

float	*init_tab(float *tab, int max)
{
	int	i;

	i = 0;
	while (i <= max)
		tab[i++] = 0;
	return (tab);
}
