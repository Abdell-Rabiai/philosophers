/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:42:51 by arabiai           #+#    #+#             */
/*   Updated: 2023/06/25 18:41:49 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <ctype.h>
# include <stdbool.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/errno.h>
# include <sys/time.h>
# include <pthread.h>

# define SLEEP 0
# define FORK_RIGHT 1
# define FORK_LEFT -1
# define EAT 2
# define THINK 3
# define DEAD 4
# define DONE 5

typedef struct s_jean_paul_sartre
{
	int							id;
	pthread_t					thread;
	pthread_mutex_t				ferchitta;
	size_t						last_meal_time;
	int							number_of_meals_eaten;
	void						*(*f)(void *);
	struct s_jean_paul_sartre	*next;
	struct s_data				*my_data;
}	t_nietzsche;

typedef struct s_data
{
	t_nietzsche		*nietzsche;
	int				how_many_platos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				nums_times_philo_must_eat;
	long			initial_time;
	int				finish;
	int				philo_died;
	int				all_died;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	edit_mutex;
	pthread_mutex_t	meals_mutex;
}	t_data;

/*----------------PETITE_PARSING----------------*/
int				check_arguments(int ac, char **av);
int				parsing(int ac, char **av);
void			initialize_data(t_data *socrates, char **av);

/*----------------PHILOSOPHY----------------*/
long			ft_get_current_time(void);
void			create_threads(t_data *socrates);
void			*start_philosophizing(void *node);
void			prepare_the_threads(t_nietzsche *my_list);
void			check_the_philosophers(t_data *data);
void			prepare_the_table(t_data *data);
void			take_the_forks_and_eat(t_nietzsche *node);
void			go_eat(t_nietzsche *node);
void			go_sleep(t_nietzsche *node);
void			go_think(t_nietzsche *node);
void			ft_sleep(int time_in_ms);
int				go_print(int b, t_nietzsche *node, t_data *data);

/*----------------utils_functions----------------*/
int				ft_atoi(const char *str);
t_nietzsche		*ft_lstnew(int id, void *(*f)(void *), t_data *socrates);
void			ft_lstadd_front(t_nietzsche **lst, t_nietzsche *new);
int				ft_lstsize(t_nietzsche *lst);
t_nietzsche		*ft_lstlast(t_nietzsche *lst);
void			ft_lstadd_back(t_nietzsche **lst, t_nietzsche *new);
void			ft_lstdelone(t_nietzsche *lst, void (*del)(void*));
void			ft_lstclear(t_nietzsche **lst, void (*del)(void*));
void			ft_lstiter(t_nietzsche *lst, void (*f)(void *));

#endif
