/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 08:55:21 by plisieck          #+#    #+#             */
/*   Updated: 2015/06/05 16:13:39 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

int		contain(char *str, char c)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == c)
			return (1);
		i++;
	}
	return (0);
}

int		main(int argc, char **argv)
{
	int		max;
	char	*str;
	char	**tab;
	float	*left;
	float	*right;

	if (argc != 2 || ft_strequ(argv[1], ""))
		print_error(1);
	str = epur_str(argv[1], ' ');
	if (!contain(str, '='))
		str = ft_strjoin(str, ft_strdup("=0"));
	if (!ft_strlen(str))
		print_error(1);
	str = treat_natural_shape(str);
	check_validity(str);
	max = get_max(str);
	tab = ft_strsplit(str, '=');
	left = get_values(split_str(tab[0]), max);
	right = get_values(split_str(tab[1]), max);
	left = sub_tabs(left, right, max);
	print_result(left, max);
	return (0);
}
