/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   computor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: plisieck <plisieck@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/03/31 08:55:52 by plisieck          #+#    #+#             */
/*   Updated: 2015/06/09 23:11:06 by plisieck         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COMPUTOR_H
# define COMPUTOR_H

# include "libft/libft.h"
# include "mlx.h"
# include <math.h>

char	*epur_str(char *str, char c);
void	print_error(int id);
char	*ft_charjoin(char *str, char c);
char	*ft_insert_str(char *str, char *insert, int pos);
void	check_validity2(char *str, int *i);

void	check_validity(char *str);
int		is_sign(char c);
float	get_val(char *str);
char	*print_float(float nb);
int		get_power(char *str);

int		count_parts(char *str);
char	**split_str(char *str);
int		get_degree(char **tab);
char	*get_reduced_form2(float *tab, char *str, int i);
char	*get_reduced_form(float *tab, int max);

float	get_swrt(float a, float x, int cpt);
int		check_all_tab(float *tab, int max);
void	print_result2(float delta, float *tab);
void	print_result3(float *tab, int degree);
void	print_result4(float *tab);

void	print_result(float *tab, int max);
int		ft_tablen(char **tab);
float	find_val(char **tab, int power);
int		power_exist(char **tab, int power);
float	*init_tab(float *tab, int max);

float	*get_values(char **tab, int max);
float	*sub_tabs(float *left, float *right, int max);
char	*treat_natural_shape2(char *str, int *i);
char	*treat_natural_shape(char *str);
int		get_max(char *str);

void	print_discriminant(float *tab, float delta);
void	do_mlx(float *tab);

#endif
