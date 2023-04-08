/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:08:46 by arabiai           #+#    #+#             */
/*   Updated: 2023/04/08 12:33:31 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"


t_nietzsche	*ft_lstnew(int id, void *(*f)(void *))
{
	t_nietzsche	*new_node;
	pthread_t	thread;

	new_node = (t_nietzsche *)malloc(sizeof(t_nietzsche));
	if (!new_node)
		return (NULL);
	new_node->id = id;
	new_node->last_meal = 0;
	new_node->number_of_meals = 0;
	new_node->f = f;
	new_node->next = NULL;
	if (pthread_mutex_init(&new_node->ferchitta, NULL))
		return (NULL);
	if (pthread_create(&thread, NULL, f, (void *)new_node))
		return (NULL);
	new_node->thread = thread;
	return (new_node);
}
