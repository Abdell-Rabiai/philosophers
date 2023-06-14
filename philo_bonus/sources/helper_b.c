/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:47:58 by arabiai           #+#    #+#             */
/*   Updated: 2023/06/14 18:34:32 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	*have_all_eaten(void *dat)
{
	t_data	*data;
	int		i;

	data = dat;
	i = 0;
	while (i < data->how_many_platos)
	{
		sem_wait(data->all_eat_sem);
		i++;
	}
	sem_wait(data->print_semaphore);
	ft_printf(1, "\001\033[1;31m\033[4;31m\002\002%d | All"
		"philosophers have eaten enough\n\033[0m",
		ft_get_current_time() - data->initial_time);
	sem_post(data->finish_the_program);
	exit(EXIT_SUCCESS);
	return (NULL);
}

void	check_is_all_eaten_enough(t_data *data)
{
	int	tid;

	if (data->nums_times_philo_must_eat == -1)
		return ;
	else
	{
		tid = pthread_create(&data->eat_check_t, NULL, &have_all_eaten, data);
		if (tid != 0)
		{
			printf("Error in thread creation\n");
			return ;
		}
		pthread_detach(data->eat_check_t);
	}
}

void	do_routine_and_check_death(t_nietzsche *philo)
{
	int	t;

	t = death_checker(philo);
	if (t != 0)
		return ;
	start_philosophizing(philo);
}

void	go_print2_b(int b, t_data *data)
{
	if (b == DONE)
	{
		ft_printf(1, "\001\033[1;31m\033[4;31m\002\002%d | All "
			"philosophers have eaten enough\n\033[0m",
			ft_get_current_time() - data->initial_time);
		exit(EXIT_SUCCESS);
	}
	else if (b == DEAD)
	{
		ft_printf(1, "\001\033[1;31m\033[4;31m\002\002%d | "
			" Philosopher %d is DEAD\n\033[0m",
			ft_get_current_time() - data->initial_time, data->nietzsche->id);
		exit(EXIT_SUCCESS);
	}
}

void	go_print_b(int b, t_data *data)
{
	sem_wait(data->print_semaphore);
	if (b == FORK)
		ft_printf(1, "\001\033[4;32m\002%d | Philosopher %d has "
			"taken both chopsticks\033[0m\n",
			ft_get_current_time() - data->initial_time, data->nietzsche->id);
	else if (b == EAT)
		ft_printf(1, "\001\033[4;33m\002%d | Philosopher %d is eating\n\033[0m",
			ft_get_current_time() - data->initial_time, data->nietzsche->id);
	else if (b == SLEEP)
		ft_printf(1, "\001\033[4;35m\002%d | Philosopher %d is sleeping\n\033[0m",
			ft_get_current_time() - data->initial_time, data->nietzsche->id);
	else if (b == THINK)
		ft_printf(1, "\001\033[4;36m\002%d | Philosopher %d is thinking\n\033[0m",
			ft_get_current_time() - data->initial_time, data->nietzsche->id);
	else
		go_print2_b(b, data);
	sem_post(data->print_semaphore);
}
