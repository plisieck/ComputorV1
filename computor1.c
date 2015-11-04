/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 15:40:37 by plisieck          #+#    #+#             */
/*   Updated: 2015/06/09 19:10:24 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

char	*epur_str(char *str, char c)
{
	int		i;
	int		j;
	char	*new;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
			j++;
		i++;
	}
	new = (char *)malloc(sizeof(char) * (j + 1));
	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] != c)
			new[j++] = str[i];
		i++;
	}
	new[j] = '\0';
	return (new);
}

void	print_error(int id)
{
	if (id == 1)
		ft_putendl("\033[31mError : \033[0mPlease enter a valid equation.");
	else if (id == 2)
		ft_putendl("\033[31mError : \033[0mWrong format");
	else if (id == 3)
		ft_putendl(ft_strjoin("The polynomial degree is stricly greater than ",
					"2, \033[31mI can't solve\033[0m."));
	exit(-1);
}

char	*ft_charjoin(char *str, char c)
{
	int		i;
	char	*new;

	i = 0;
	new = (char *)malloc(sizeof(char) * (ft_strlen(str) + 2));
	while (str[i])
	{
		new[i] = str[i];
		i++;
	}
	new[i++] = c;
	new[i] = '\0';
	return (new);
}

char	*ft_insert_str(char *str, char *insert, int pos)
{
	return (ft_strjoin(ft_strsub(str, 0, pos),
	ft_strjoin(insert, ft_strsub(str, pos, ft_strlen(str) - pos))));
}

void	check_validity2(char *str, int *i)
{
	if (!ft_isdigit(str[*i]) && str[*i] != '-' && str[*i] != '+')
		print_error(2);
	else
	{
		if (str[*i] == '-' || str[*i] == '+')
			(*i)++;
		while (str[*i] && (ft_isdigit(str[*i]) || str[*i] == '.'))
			(*i)++;
	}
}
