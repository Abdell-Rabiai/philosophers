/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main_utils_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:46:55 by arabiai           #+#    #+#             */
/*   Updated: 2023/05/25 18:21:56 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	ft_sleep(int time_in_ms)
{
	long	time_initiale;

	time_initiale = ft_get_current_time();
	while (ft_get_current_time() - time_initiale < time_in_ms)
		usleep(200);
}

void	*start_philosophizing(void *dat)
{
	t_data *data;
	
	data = dat;
	data->initial_time = ft_get_current_time();
	while (1)
	{
		take_the_forks_and_eat(data);
		go_sleep_think(data);
	}
	return (NULL);
}

int	death_checker(t_data *data)
{
	int t;
	
	data->nietzsche->last_meal_time = ft_get_current_time();
	t = pthread_create(&data->death_check_t, NULL, &check_the_philosophers, data);
	if (t != 0)
		return (printf("Error in thread creation\n"), sem_post(data->finish_the_program));
	pthread_detach(data->death_check_t);
	return (0);
}

void	prepare_the_processes(t_data *data)
{
	int			i;
	pid_t 		pid;

	i = 1;
	// data->initial_time = ft_get_current_time();
	while (i <= data->how_many_platos)
	{
		data->nietzsche->id = i;
		pid = fork();
		if (pid == 0)
		{
			death_checker(data);
			start_philosophizing(data);
		}
		i++;
	}
	sem_wait(data->finish_the_program);
}

void	*check_the_philosophers(void *d)
{
	t_data 		*data;
	size_t		time;

	data = (t_data *)d;
	while (true)
	{
		time = ft_get_current_time();
		if ((time - data->nietzsche->last_meal_time > data->time_to_die))
		{
			sem_wait(data->print_semaphore);
			ft_printf(1, "\001\033[1;31m\033[4;31m\002\002%d | "
			"Philosopher %d is DEAD\n\033[0m",
			ft_get_current_time() - data->initial_time, data->nietzsche->id);
			sem_post(data->finish_the_program);
			exit(EXIT_SUCCESS);
		}
	}
	return (NULL);
}
