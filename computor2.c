/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/05 15:46:36 by plisieck          #+#    #+#             */
/*   Updated: 2015/06/07 20:36:21 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	check_validity(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		check_validity2(str, &i);
		if (str[i++] != '*')
			print_error(2);
		if (str[i] != 'X' && str[i] != 'x')
			print_error(2);
		i++;
		if (str[i++] != '^')
			print_error(2);
		if (!ft_isdigit(str[i]))
			print_error(2);
		while (str[i] && ft_isdigit(str[i]))
			i++;
		if (!str[i])
			break ;
		if (str[i] != '+' && str[i] != '-' && str[i] != '*' && str[i] != '=')
			print_error(2);
		i++;
	}
}

int		is_sign(char c)
{
	return ((c == '-' || c == '+') ? 1 : 0);
}

float	get_val(char *str)
{
	int		i;
	char	*tmp;

	tmp = "";
	i = 0;
	if (str[0] != '-' && str[0] != '+')
		str = ft_strjoin("+", str);
	while (str[i] && (ft_isdigit(str[i]) || str[i] == '.' || is_sign(str[i])))
		tmp = ft_charjoin(tmp, str[i++]);
	return (ft_atof(tmp));
}

char	*print_float(float nb)
{
	int				cpt;
	char			*s;
	long long int	ent;
	long long int	dec;
	char			*std;

	cpt = 0;
	ent = (long long int)nb;
	dec = llrint(((nb - (long long int)nb) * 1000000));
	s = ft_strdup((nb < 0 && !ent ? "-" : ""));
	if (dec < 0)
		dec = -dec;
	std = ft_itoa(dec);
	while (ft_strlen(std) < 6)
		std = ft_strjoin("0", std);
	while (std[ft_strlen(std) - 1] == '0')
		std = ft_strsub(std, 0, ft_strlen(std) - 1);
	if (dec)
		return (ft_strjoin(s, ft_strjoin(ft_itoa(ent), ft_strjoin(".", std))));
	return (ft_strjoin(s, ft_itoa(ent)));
}

int		get_power(char *str)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = "";
	while (str[i] && str[i] != '^')
		i++;
	i++;
	while (str[i])
		tmp = ft_charjoin(tmp, str[i++]);
	return (ft_atoi(tmp));
}
