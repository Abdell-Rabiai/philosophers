/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 21:47:58 by arabiai           #+#    #+#             */
/*   Updated: 2023/06/11 18:39:28 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	free_everything(t_data *data)
{
	t_nietzsche	*tmp;
	t_nietzsche	*tmp2;

	tmp = data->nietzsche;
	while (tmp->next != data->nietzsche)
	{
		tmp2 = tmp;
		tmp = tmp->next;
		free(tmp2);
		pthread_mutex_destroy(&tmp2->ferchitta);
	}
	free(tmp);
	pthread_mutex_destroy(&data->print_mutex);
	pthread_mutex_destroy(&data->edit_mutex);
}

int	go_print2(int b, t_nietzsche *node, t_data *data)
{
	if (b == DONE)
	{
		ft_printf(1, "\001\033[1;31m\033[4;31m\002\002%d | All "
			"philosophers have eaten enough\n\033[0m",
			ft_get_current_time() - data->initial_time);
		free_everything(data);
		return (1);
	}
	else if (b == DEAD)
	{
		ft_printf(1, "\001\033[1;31m\033[4;31m\002\002%d | "
			"Philosopher %d is DEAD\n\033[0m",
			ft_get_current_time() - data->initial_time, node->id);
		free_everything(data);
		return (1);
	}
	return (0);
}

int	go_print(int b, t_nietzsche *node, t_data *data)
{
	pthread_mutex_lock(&node->my_data->print_mutex);
	if (b == FORK)
		ft_printf(1, "\001\033[4;32m\002%d | Philosopher %d has "
			"taken both chopsticks\033[0m\n",
			ft_get_current_time() - node->my_data->initial_time, node->id);
	else if (b == EAT)
		ft_printf(1, "\001\033[4;33m\002%d | Philosopher %d is eating\n\033[0m",
			ft_get_current_time() - node->my_data->initial_time, node->id);
	else if (b == SLEEP)
		ft_printf(1, "\001\033[4;35m\002%d | Philosopher %d is sleeping\n\033[0m",
			ft_get_current_time() - node->my_data->initial_time, node->id);
	else if (b == THINK)
		ft_printf(1, "\001\033[4;36m\002%d | Philosopher %d is thinking\n\033[0m",
			ft_get_current_time() - node->my_data->initial_time, node->id);
	else
	{
		if (go_print2(b, node, data) == 1)
			return (1);
	}
	pthread_mutex_unlock(&node->my_data->print_mutex);
	return (0);
}
