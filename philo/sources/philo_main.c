/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:39:45 by arabiai           #+#    #+#             */
/*   Updated: 2023/04/11 22:17:20 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

void slp(int time_in_ms)
{
	long long time_initiale = ft_get_current_time();
	while (ft_get_current_time() - time_initiale < time_in_ms)
		usleep(10);
}

void take_the_forks_and_eat(t_nietzsche *node)
{
	pthread_mutex_lock(&node->ferchitta);
	pthread_mutex_lock(&node->next->ferchitta);
	pthread_mutex_lock(&node->my_data->print_mutex);
	ft_printf(1, "%d | Philosopher %d has taken both chopsticks\n", ft_get_current_time() - node->my_data->initial_time, node->id);
	pthread_mutex_unlock(&node->my_data->print_mutex);
	go_eat(node);
	pthread_mutex_unlock(&node->ferchitta);
	pthread_mutex_unlock(&node->next->ferchitta);
}

void go_eat(t_nietzsche *node)
{

	pthread_mutex_lock(&node->my_data->print_mutex);
	ft_printf(1, "%d | Philosopher %d is eating\n", ft_get_current_time() - node->my_data->initial_time, node->id);
	pthread_mutex_unlock(&node->my_data->print_mutex);
	pthread_mutex_lock(&node->my_data->edit_mutex);
	node->number_of_meals_eaten++;
	node->last_meal_time = ft_get_current_time();
	pthread_mutex_unlock(&node->my_data->edit_mutex);
	slp(node->my_data->time_to_eat);
}

void go_sleep(t_nietzsche *node)
{
	pthread_mutex_lock(&node->my_data->print_mutex);
	ft_printf(1, "%d | Philosopher %d is sleeping\n", ft_get_current_time() - node->my_data->initial_time, node->id);
	pthread_mutex_unlock(&node->my_data->print_mutex);
	pthread_mutex_lock(&node->my_data->edit_mutex);
	pthread_mutex_unlock(&node->my_data->edit_mutex);
	slp(node->my_data->time_to_sleep);
}

void go_think(t_nietzsche *node)
{
	pthread_mutex_lock(&node->my_data->print_mutex);
	ft_printf(1, "%d | Philosopher %d is thinking\n", ft_get_current_time() - node->my_data->initial_time, node->id);
	pthread_mutex_unlock(&node->my_data->print_mutex);
}

void	*start_philosophizing(void *node)
{
	t_nietzsche *tmp;

	tmp = (t_nietzsche *)node;
	if (tmp->id % 2)
		usleep(100);
	while (true)
	{
		take_the_forks_and_eat(tmp);
		go_sleep(tmp);
		go_think(tmp);
		usleep(30);
	}
	return (NULL);
}

void prepare_the_threads(t_nietzsche *my_list)
{
	t_nietzsche *tmp;

	tmp = my_list;
	while (tmp->next != my_list)
	{
		pthread_create(&tmp->thread, NULL, tmp->f, tmp);
		tmp = tmp->next;
		usleep(100);
	}
	pthread_create(&tmp->thread, NULL, tmp->f, tmp);
}

void prepare_the_table(t_data *data)
{
	int 		i;
	t_nietzsche *my_list;
	t_nietzsche *new_node;
	t_nietzsche *tmp;

	i = 1;	
	my_list = ft_lstnew(i, start_philosophizing, data);
	i++;
	while (i <= data->how_many_platos)
	{
		new_node = ft_lstnew(i, start_philosophizing, data);
		ft_lstadd_back(&my_list, new_node);
		i++;
	}	
	tmp = ft_lstlast(my_list);
	tmp->next = my_list;
	data->nietzsche = my_list;
	prepare_the_threads(my_list);
}

int all_philosophers_have_eaten_enough(t_data *data)
{
	t_nietzsche *temp;
	int i;

	i = 0;
	temp = data->nietzsche;
	while (temp->next != data->nietzsche)
	{
		if (temp->number_of_meals_eaten >= data->end_of_program)
			i++;
		temp = temp->next;
	}
	if (temp->number_of_meals_eaten >= data->end_of_program)
		i++;
	if (i == data->how_many_platos)
		return (1);
	return (0);
}
void check_the_philosophers(t_data *data)
{
	t_nietzsche *temp;

	temp = data->nietzsche;

	while (true)
	{
		pthread_mutex_lock(&data->edit_mutex);
		if ((ft_get_current_time() - temp->last_meal_time >= data->time_to_die))
		{
			pthread_mutex_lock(&data->print_mutex);
			ft_printf(1, "%d | Philosopher %d is dead lah ir7mou\n", ft_get_current_time() - data->initial_time, temp->id);
			exit(EXIT_SUCCESS);
		}
		else if (data->end_of_program != -1 && all_philosophers_have_eaten_enough(data))
		{
			pthread_mutex_lock(&data->print_mutex);
			ft_printf(1, "%d | All philosophers have eaten enough\n",ft_get_current_time() - data->initial_time);
			exit(EXIT_SUCCESS);
		}
		temp = temp->next;
		pthread_mutex_unlock(&data->edit_mutex);
		slp(100);
	}
}

int main(int ac, char **av)
{
	t_data data;

	if (parsing(ac, av))
		return (0);
	initialize_data(&data, av);
	prepare_the_table(&data);
	check_the_philosophers(&data);
	return (0);
}