/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 20:46:55 by arabiai           #+#    #+#             */
/*   Updated: 2023/06/24 04:00:29 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_sleep(int time_in_ms)
{
	long	time_initiale;

	time_initiale = ft_get_current_time();
	while (ft_get_current_time() - time_initiale < time_in_ms)
		usleep(200);
}

void	*start_philosophizing(void *node)
{
	t_nietzsche	*tmp;

	tmp = (t_nietzsche *)node;
	if (tmp->id % 2 == 0)
		ft_sleep(200);
	while (true)
	{
		take_the_forks_and_eat(tmp);
		go_sleep(tmp);
		go_think(tmp);
	}
	return (NULL);
}

void	prepare_the_threads(t_nietzsche *my_list)
{
	t_nietzsche	*tmp;

	tmp = my_list;
	while (tmp->next != my_list)
	{
		pthread_create(&tmp->thread, NULL, tmp->f, tmp);
		pthread_detach(tmp->thread);
		tmp = tmp->next;
		usleep(100);
	}
	pthread_create(&tmp->thread, NULL, tmp->f, tmp);
	pthread_detach(tmp->thread);
	usleep(100);
}

void	prepare_the_table(t_data *data)
{
	int			i;
	t_nietzsche	*my_list;
	t_nietzsche	*new_node;
	t_nietzsche	*tmp;

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

void	check_the_philosophers(t_data *data)
{
	t_nietzsche	*temp;

	temp = data->nietzsche;
	while (true)
	{
		pthread_mutex_lock(&data->edit_mutex);
		if ((ft_get_current_time() - temp->last_meal_time >= data->time_to_die))
		{
			if (go_print(DEAD, temp, data))
				return ;
		}
		else if (data->nums_times_philo_must_eat != -1
			&& data->finish == data->how_many_platos)
		{
			if (go_print(DONE, temp, data))
				return ;
		}
		temp = temp->next;
		pthread_mutex_unlock(&data->edit_mutex);
		usleep(300);
	}
}
