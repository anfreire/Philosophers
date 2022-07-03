/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:52:50 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/03 12:00:19 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


int	main(int argc, char **argv)
{
	t_data	data;

	if (check_args(argc, argv))
		return (0);
	atributte_args(argc, argv, &data);
	create_mutex(&data);
	create_philos(&data);
	join_philos(&data);
	destroy_mutex(&data);
	return (0);
}