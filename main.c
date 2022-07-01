/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:52:50 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/01 13:18:06 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv))
		return (0);
	atributte_args(argc, argv, &data);
	int i;
	i = 0;
	while (data.philo.forks[i] != 0)
	{
		printf("%d\n", data.philo.forks[i]);
		i++;
	}
	
}