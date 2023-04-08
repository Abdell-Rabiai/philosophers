/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:39:45 by arabiai           #+#    #+#             */
/*   Updated: 2023/04/08 12:43:35 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/time.h>

void go_eat(t_nietzsche *node)
{
	// pthread_mutex_lock(&node->ferchitta);
	// pthread_mutex_lock(&node->next->ferchitta);
	printf("Philosopher %d is eating\n", node->id);
	// pthread_mutex_unlock(&node->ferchitta);
	// pthread_mutex_unlock(&node->next->ferchitta);
	usleep(1000000);
}

void	*start_philosophizing(void *node)
{
	while (true)
	{
		go_eat((t_nietzsche *)node);
		// go_sleep((t_nietzsche *)node);
		// go_think((t_nietzsche *)node);	
	}
	return (NULL);
}

void prepare_the_table(t_data *data)
{
	int i;
	t_nietzsche *my_list;
	t_nietzsche *new_node;

	// t_nietzsche *tmp;
	i = 1;
	
	my_list = ft_lstnew(i, start_philosophizing);
	i++;
	printf("{%d}\n", data->how_many_platos);
	while (i <= data->how_many_platos)
	{
		printf("Added [%d]\n", i);
		new_node = ft_lstnew(i, start_philosophizing);
		ft_lstadd_back(&my_list, new_node);
		i++;
	}
	// tmp = ft_lstlast(my_list);
	// tmp->next = my_list;

	// printf("%d\n", my_list->id);
	// printf("%d\n", my_list->next->id);
	// printf("%d\n", my_list->next->next->id);
	// printf("%d\n", my_list->next->next->next->id);
	// printf("%d\n", my_list->next->next->next->next->id);
}

int main(int ac, char **av)
{
	t_data data;;

	if (parsing(ac, av))
		return (0);
	initialize_data(&data, av);
	prepare_the_table(&data);
	// philosophy(&data);
	return (0);
}