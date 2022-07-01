/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 11:10:26 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/01 11:44:13 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	check_if_digit(char *str)
{
	if (ft_isdigit(str))
		return (1);
	return (0);
}

int	check_args(int argc, char **argv)
{
	int	i;
	
	i = 0;
	if (argc < 5 || argc > 6)
		return (1);
	while (argv[++i])
	{
		if (check_if_digit(argv[i]))
			return (1);
	}
	return (0);
}