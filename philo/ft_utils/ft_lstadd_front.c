/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:21:51 by arabiai           #+#    #+#             */
/*   Updated: 2023/04/08 15:19:13 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_lstadd_front(t_nietzsche **lst, t_nietzsche *new)
{
	if (!lst || !new)
		return ;
	new->next = *lst;
	*lst = new;
}
