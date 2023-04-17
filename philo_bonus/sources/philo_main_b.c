/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main_b.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:39:45 by arabiai           #+#    #+#             */
/*   Updated: 2023/04/17 21:34:03 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	take_the_forks_and_eat(t_nietzsche *node)
{
	sem_wait(node->my_data->chopsticks);
	sem_wait(node->my_data->chopsticks);
	go_print(FORK, node, node->my_data);
	go_eat(node);
	sem_post(node->my_data->chopsticks);
	sem_post(node->my_data->chopsticks);
}

void	go_eat(t_nietzsche *node)
{
	go_print(EAT, node, node->my_data);
	node->number_of_meals_eaten++;
	node->last_meal_time = ft_get_current_time();
	if (node->number_of_meals_eaten == node->my_data->nums_times_philo_must_eat)
		node->my_data->finish++;
	ft_sleep(node->my_data->time_to_eat);
}

void	go_sleep(t_nietzsche *node)
{
	go_print(SLEEP, node, node->my_data);
	ft_sleep(node->my_data->time_to_sleep);
}

void	go_think(t_nietzsche *node)
{
	go_print(THINK, node, node->my_data);
}

void prepare_the_semapores(t_data *data)
{
	sem_unlink("chopsticks");
	sem_unlink("print_semaphore");
	sem_unlink("edit_semaphore");
	sem_unlink("wait_semaphore");
	data->chopsticks = sem_open("chopsticks", O_CREAT, 0644, data->how_many_platos);
	data->print_semaphore = sem_open("print_semaphore", O_CREAT, 0644, 1);
	data->edit_semaphore = sem_open("edit_semaphore", O_CREAT, 0644, 1);
	data->wait_semaphore = sem_open("wait_semaphore", O_CREAT, 0644, 1);
}

int	main(int ac, char **av)
{
	t_data	data;

	if (parsing(ac, av))
		return (0);
	initialize_data(&data, av);
	prepare_the_semapores(&data);
	prepare_the_table(&data);
	check_the_philosophers(&data);
	return (0);
}
