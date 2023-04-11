/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:08:46 by arabiai           #+#    #+#             */
/*   Updated: 2023/04/11 21:52:00 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

t_nietzsche	*ft_lstnew(int id, void *(*f)(void *), t_data *socrates)
{
	t_nietzsche	*new_node;

	new_node = (t_nietzsche *)malloc(sizeof(t_nietzsche));
	if (!new_node)
		return (NULL);
	new_node->id = id;
	new_node->number_of_meals_eaten = 0;
	new_node->f = f;
	new_node->next = NULL;
	new_node->my_data = socrates;
	new_node->last_meal_time = socrates->initial_time;
	if (pthread_mutex_init(&new_node->ferchitta, NULL))
		return (NULL);
	return (new_node);
}
