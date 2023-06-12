/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:39:45 by arabiai           #+#    #+#             */
/*   Updated: 2023/06/12 13:53:26 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	take_the_forks_and_eat(t_nietzsche *node)
{
	pthread_mutex_lock(&node->ferchitta);
	pthread_mutex_lock(&node->next->ferchitta);
	go_print(FORK, node, node->my_data);
	go_eat(node);
	pthread_mutex_unlock(&node->ferchitta);
	pthread_mutex_unlock(&node->next->ferchitta);
}

void	go_eat(t_nietzsche *node)
{
	go_print(EAT, node, node->my_data);
	pthread_mutex_lock(&node->my_data->edit_mutex);
	node->number_of_meals_eaten++;
	node->last_meal_time = ft_get_current_time();
	if (node->number_of_meals_eaten == node->my_data->nums_times_philo_must_eat)
		node->my_data->finish++;
	pthread_mutex_unlock(&node->my_data->edit_mutex);
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

int	main(int ac, char **av)
{
	t_data	*data;

	if (parsing(ac, av))
		return (0);
	data = (t_data *)malloc(sizeof(t_data));
	initialize_data(data, av);
	prepare_the_table(data);
	check_the_philosophers(data);
	return (0);
}
