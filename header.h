/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anfreire <anfreire@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/01 10:52:07 by anfreire          #+#    #+#             */
/*   Updated: 2022/07/03 09:35:21 by anfreire         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HEADER_H
#define HEADER_H

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <time.h>
#include <string.h>

typedef	struct s_philo
{
	pthread_t	*philos;
	int			*forks;
}				t_philo;


typedef struct s_data
{
	int				nmbr_philos;
	int				nmbr_thread;
	struct	timeval	t_start;
	long			t_eat;
	long			t_die;
	long			t_sleep;
	int				nmbr_philo_eat;
	t_philo			philo;
}				t_data;

//routine
void	*routine(void *args);

//errors
int	check_if_digit(char *str);
int	check_args(int argc, char **argv);


//process
void		atributte_args(int argc, char **argv, t_data *data);
void		put_forks(t_data *data);
void		create_philos(t_data *data);
void		join_philos(t_data *data);
long long	get_miliseconds(t_data *data);

//utils
int		ft_isdigit(char *str);
int		ft_atoi(char *str);
char	*ft_itoa(int n);

#endif