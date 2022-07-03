/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 12:27:59 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/03 17:07:12 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"

void*	routine(void *args)
{
	t_data	*data;
	
	data = (t_data *)args;
	while (1)
	{	
		philo_eats(data, data->nmbr_thread);
	}
	return (NULL);
	// printf("%lld	", get_miliseconds(data));
	// printf("%d\n", data->nmbr_thread);
}