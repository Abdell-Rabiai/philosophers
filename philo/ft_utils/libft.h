/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:50:46 by arabiai           #+#    #+#             */
/*   Updated: 2023/04/08 12:27:38 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_jean_paul_sartre
{
	int										id;
	pthread_t								thread;
	pthread_mutex_t					 		ferchitta;
	size_t									last_meal;
	int										number_of_meals;
	void									*(*f)(void *);
	struct s_jean_paul_sartre				*next;
}	t_nietzsche;

int				ft_atoi(const char *str);
t_nietzsche		*ft_lstnew(int id, void *(*f)(void *));
void			ft_lstadd_front(t_nietzsche **lst, t_nietzsche *new);
int				ft_lstsize(t_nietzsche *lst);
t_nietzsche		*ft_lstlast(t_nietzsche *lst);
void			ft_lstadd_back(t_nietzsche **lst, t_nietzsche *new);
void			ft_lstdelone(t_nietzsche *lst, void (*del)(void*));
void			ft_lstclear(t_nietzsche **lst, void (*del)(void*));
void			ft_lstiter(t_nietzsche *lst, void (*f)(void *));
t_nietzsche		*ft_lstmap(t_nietzsche *lst, void *(*f)(void *), void (*del)(void *));

#endif
