/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/21 10:19:13 by arabiai           #+#    #+#             */
/*   Updated: 2023/04/08 06:58:09 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"libft.h"

void	ft_lstdelone(t_nietzsche *lst, void (*del)(void *))
{
	if (!lst || !del)
		return ;
	del(&lst->ferchitta);
	free(lst);
}
