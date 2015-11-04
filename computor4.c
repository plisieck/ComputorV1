/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor4.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 22:45:03 by plisieck          #+#    #+#             */
/*   Updated: 2015/06/09 23:15:56 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

float	get_sqrt(float a, float x, int cpt)
{
	x = (x + (a / x)) / 2;
	if (cpt >= 10)
		return (x);
	return (get_sqrt(a, x, ++cpt));
}

int		check_all_tab(float *tab, int max)
{
	int	i;

	i = 1;
	while (i <= max)
	{
		if (tab[i])
			return (1);
		i++;
	}
	return (0);
}

void	print_result2(float delta, float *tab)
{
	ft_putstr("The discrimiant is \033[33mstrictly negative\033[0m");
	ft_putendl(", the \033[32mtwo complex solutions\033[0m are:");
	ft_putstr(print_float(-tab[1] / (2 * tab[2])));
	ft_putstr(" + ");
	if (ft_strcmp("1", print_float(get_sqrt(-delta, 1, 0) / (2 * tab[2]))))
		ft_putstr(print_float(get_sqrt(-delta, 1, 0) / (2 * tab[2])));
	ft_putendl("i ");
	ft_putstr(print_float(-tab[1] / (2 * tab[2])));
	ft_putstr(" - ");
	if (ft_strcmp("1", print_float(get_sqrt(-delta, 1, 0) / (2 * tab[2]))))
		ft_putstr(print_float(get_sqrt(-delta, 1, 0) / (2 * tab[2])));
	ft_putendl("i ");
}

void	print_result3(float *tab, int degree)
{
	ft_putstr("The \033[32msolution \033[0mis: ");
	if (degree == 0)
		ft_putendl(print_float(tab[0]));
	else
		ft_putendl(print_float(tab[0] / -tab[1]));
}

void	print_result4(float *tab)
{
	float delta;

	delta = (tab[1] * tab[1]) - (4 * (tab[2] * tab[0]));
	print_discriminant(tab, delta);
	if (delta == 0)
	{
		ft_putstr("The discriminant is \033[33mnull\033[0m");
		ft_putendl(", the \033[32msolution \033[0mis:");
		ft_putendl(print_float(-tab[1] / (2 * tab[2])));
	}
	else if (delta > 0)
	{
		ft_putstr("The discriminant is \033[33m");
		ft_putstr("strictly positive\033[0m");
		ft_putendl(", the \033[32mtwo solutions\033[0m are:");
		ft_putendl(print_float((-tab[1] +
						get_sqrt(delta, 1, 0)) / (2 * tab[2])));
		ft_putendl(print_float((-tab[1] -
						get_sqrt(delta, 1, 0)) / (2 * tab[2])));
	}
	else if (delta < 0)
		print_result2(delta, tab);
}
