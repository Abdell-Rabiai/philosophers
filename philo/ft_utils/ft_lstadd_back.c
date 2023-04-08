/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:22:27 by arabiai           #+#    #+#             */
/*   Updated: 2023/04/08 13:37:33 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstadd_back(t_nietzsche **lst, t_nietzsche *new)
{
	t_nietzsche	*temp;

	if (!new)
		return ;
	if (!(*lst))
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next != NULL)
			temp = temp->next;
		temp->next = new;
	}
}

// void	ft_lstadd_back(t_nietzsche **lst, t_nietzsche *new)
// {
// 	t_nietzsche	*temp;

// 	if (!new)
// 		return ;
// 	new->next = *lst;
// 	temp = *lst;
// 	if ((*lst))
// 	{
// 		while (1)
// 		{
// 			temp = temp->next;
// 			if (temp->next == *lst)
// 				break ;
// 		}
// 		temp->next = new;
// 	}
// 	else
// 		*lst = new;
// }

// t_list	*get_list(t_list *list, t_info *info)
// {
// 	int	i;

// 	i = 0;
// 	list = new_thread(info, 1);
// 	while (++i < info->philo_num)
// 		ft_lstadd_back(&list, new_thread(info, i + 1));
// 	return (list);
// }