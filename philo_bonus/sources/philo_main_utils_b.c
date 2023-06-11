/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main_utils_b.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:46:55 by arabiai           #+#    #+#             */
/*   Updated: 2023/06/11 14:18:32 by arabiai          ###   ########.fr       */
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

void	start_philosophizing(t_nietzsche *philo)
{
	while (1)
	{
		take_the_forks_and_eat(philo);
		go_sleep_think(philo);
		usleep(300);
	}
}

int	death_checker(t_nietzsche *philo)
{
	int	t;

	philo->last_meal_time = ft_get_current_time();
	t = pthread_create(&philo->death_check_t, NULL,
			&check_the_philosophers, philo);
	if (t != 0)
	{
		printf("Error in thread creation\n");
		sem_post(philo->my_data->finish_the_program);
		return (1);
	}
	pthread_detach(philo->death_check_t);
	return (0);
}

void	prepare_the_processes(t_data *data)
{
	int			i;
	pid_t		pid;
	char		*name;
	char		*num;

	i = 0;
	data->initial_time = ft_get_current_time();
	while (i < data->how_many_platos)
	{
		num = ft_itoa(i);
		name = ft_strjoin("/edit_sem", num);
		unlink(name);
		pid = fork();
		data->nietzsche[i].edit_sem = sem_open(name, O_CREAT, 0644, 1);
		data->nietzsche[i].id = i + 1;
		data->nietzsche[i].number_of_meals_eaten = 0;
		data->nietzsche[i].my_data = data;
		if (pid == 0)
			do_routine_and_check_death(&data->nietzsche[i]);
		free(name);
		free(num);
		i++;
	}
	sem_wait(data->finish_the_program);
}

void	*check_the_philosophers(void *d)
{
	t_data		*data;
	t_nietzsche	*philo;

	philo = ((t_nietzsche *)d);
	data = philo->my_data;
	while (1)
	{
		if ((ft_get_current_time() - philo->last_meal_time > data->time_to_die))
		{
			sem_wait(data->print_semaphore);
			ft_printf(1, "\001\033[1;31m\033[4;31m\002\002%d | "
				"Philosopher %d is DEAD\n\033[0m",
				ft_get_current_time() - data->initial_time, philo->id);
			sem_post(data->finish_the_program);
			kill(0, SIGINT);
		}
		usleep(1500);
	}
	return (NULL);
}
