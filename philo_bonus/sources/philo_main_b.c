/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:39:45 by arabiai           #+#    #+#             */
/*   Updated: 2023/06/25 18:51:04 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	take_the_forks_and_eat(t_nietzsche *philo)
{
	t_data	*data;

	data = philo->my_data;
	sem_wait(data->chopsticks);
	sem_wait(data->print_semaphore);
	printf("\001\033[4;32m\002%ld | Philosopher %d has"
		"taken the RIGHT chopstick\033[0m\n",
		ft_get_current_time() - data->initial_time, philo->id);
	sem_post(data->print_semaphore);
	sem_wait(data->chopsticks);
	sem_wait(data->print_semaphore);
	printf("\001\033[4;32m\002%ld | Philosopher %d has"
		"taken the LEFT chopstick\033[0m\n",
		ft_get_current_time() - data->initial_time, philo->id);
	sem_post(data->print_semaphore);
	go_eat(philo);
	sem_post(data->chopsticks);
	sem_post(data->chopsticks);
}

void	go_eat(t_nietzsche *philo)
{
	t_data	*data;

	data = philo->my_data;
	sem_wait(data->print_semaphore);
	printf("\001\033[4;33m\002%ld | Philosopher %d is eating\n\033[0m",
		ft_get_current_time() - data->initial_time, philo->id);
	sem_post(data->print_semaphore);
	ft_sleep(data->time_to_eat);
	sem_wait(philo->edit_sem);
	philo->number_of_meals_eaten++;
	philo->last_meal_time = ft_get_current_time();
	if (philo->number_of_meals_eaten == data->nums_times_philo_must_eat)
		sem_post(data->all_eat_sem);
	sem_post(philo->edit_sem);
}

void	go_sleep_think(t_nietzsche *philo)
{
	t_data	*data;

	data = philo->my_data;
	sem_wait(data->print_semaphore);
	printf("\001\033[4;35m\002%ld | Philosopher %d is sleeping\n\033[0m",
		ft_get_current_time() - data->initial_time, philo->id);
	sem_post(data->print_semaphore);
	ft_sleep(data->time_to_sleep);
	sem_wait(data->print_semaphore);
	printf("\001\033[4;36m\002%ld | Philosopher %d is thinking\n\033[0m",
		ft_get_current_time() - data->initial_time, philo->id);
	sem_post(data->print_semaphore);
}

void	prepare_the_semapores(t_data *data)
{
	sem_unlink("chopsticks_sem");
	sem_unlink("print_sem");
	sem_unlink("edit_sem");
	sem_unlink("all_eat_sem");
	sem_unlink("finish_the_program");
	data->chopsticks = sem_open("chopsticks_sem", O_CREAT | O_EXCL,
			0644, data->how_many_platos);
	data->print_semaphore = sem_open("print_sem", O_CREAT | O_EXCL, 0644, 1);
	data->edit_semaphore = sem_open("edit_sem", O_CREAT | O_EXCL, 0644, 1);
	if (data->nums_times_philo_must_eat != -1)
		data->all_eat_sem = sem_open("all_eat_sem", O_CREAT | O_EXCL, 0644, 0);
	data->finish_the_program = sem_open("finish_the_program",
			O_CREAT | O_EXCL, 0644, 0);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (parsing(ac, av))
		return (0);
	initialize_data(&data, av);
	prepare_the_semapores(&data);
	check_is_all_eaten_enough(&data);
	prepare_the_processes(&data);
	kill(0, SIGINT);
	return (0);
}
