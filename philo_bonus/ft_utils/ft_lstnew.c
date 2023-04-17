/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:08:46 by arabiai           #+#    #+#             */
/*   Updated: 2023/04/17 21:15:51 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

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
	new_node->last_meal_time = ft_get_current_time();
	return (new_node);
}
