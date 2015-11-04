/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor7.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/06/09 22:42:28 by plisieck          #+#    #+#             */
/*   Updated: 2015/06/09 23:02:53 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "computor.h"

void	print_discriminant(float *tab, float delta)
{
	ft_putstr(ft_strjoin("a=", print_float(tab[2])));
	ft_putstr(ft_strjoin(", b=", print_float(tab[1])));
	ft_putendl(ft_strjoin(", c=", print_float(tab[0])));
	ft_putstr("Discriminant = b");
	ft_wputchar(0xB2);
	ft_putendl(" - 4ac");
	ft_putendl(ft_strjoin("Discriminant = ", print_float(delta)));
}
