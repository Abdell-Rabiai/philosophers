/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:19:13 by arabiai           #+#    #+#             */
/*   Updated: 2023/04/08 15:19:23 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	ft_lstdelone(t_nietzsche *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(&lst->ferchitta);
	free(lst);
}
