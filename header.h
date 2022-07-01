/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:52:07 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/01 12:09:27 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct s_data
{
	int		nmbr_philos;
	time_t	t_eat;
	time_t	t_die;
	time_t	t_sleep;
	int		nmbr_philo_eat;
}				t_data;

//errors
int	check_if_digit(char *str);
int	check_args(int argc, char **argv);


//process
void	atributte_args(int argc, char **argv, t_data *philo);

//utils
int	ft_isdigit(char *str);
int	ft_atoi(char *str);

#endif