/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:39:45 by arabiai           #+#    #+#             */
/*   Updated: 2023/04/08 14:18:01 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

void my_sleep(int ms)
{
	long long start_time = ft_get_current_time();
	while (ft_get_current_time() - start_time < ms)
		usleep(100);
}

void go_eat(t_nietzsche *node)
{
	pthread_mutex_lock(&node->ferchitta);
	pthread_mutex_lock(&node->next->ferchitta);
	ft_printf(1, "Philosopher %d is eating\n", node->id);
	my_sleep(50);
	pthread_mutex_unlock(&node->ferchitta);
	pthread_mutex_unlock(&node->next->ferchitta);
}

void	*start_philosophizing(void *node)
{
	t_nietzsche *tmp;

	tmp = (t_nietzsche *)node;
	
	if (tmp->id % 2 == 0)
		usleep(100);
	while (true)
	{
		go_eat((t_nietzsche *)node);
		// go_sleep((t_nietzsche *)node);
		// go_think((t_nietzsche *)node);	
	}
	return (NULL);
}

void prepare_the_threads(t_nietzsche *my_list)
{
	t_nietzsche *tmp;
	pthread_t thread_id;

	tmp = my_list;
	while (tmp->next != my_list)
	{
		pthread_create(&thread_id, NULL, tmp->f, tmp);
		tmp = tmp->next;
	}
	pthread_create(&thread_id, NULL, tmp->f, tmp);
}

void prepare_the_table(t_data *data)
{
	int i;
	t_nietzsche *my_list;
	t_nietzsche *new_node;
	t_nietzsche *tmp;

	i = 1;	
	my_list = ft_lstnew(i, start_philosophizing);
	i++;
	while (i <= data->how_many_platos)
	{
		new_node = ft_lstnew(i, start_philosophizing);
		ft_lstadd_back(&my_list, new_node);
		i++;
	}	
	tmp = ft_lstlast(my_list);
	tmp->next = my_list;
	prepare_the_threads(my_list);
}

int main(int ac, char **av)
{
	t_data data;

	if (parsing(ac, av))
		return (0);
	initialize_data(&data, av);
	prepare_the_table(&data);
	while(1);
	// philosophy(&data);
	return (0);
}