/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:42:51 by arabiai           #+#    #+#             */
/*   Updated: 2023/05/26 17:15:25 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <ctype.h>
# include <stdbool.h>
#include  <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <signal.h>
# include <stdio.h>
# include <fcntl.h>
# include <signal.h>
# include <sys/errno.h>
# include <sys/time.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <signal.h>
# include <pthread.h>
# include <semaphore.h>
# include "ft_printf/ft_printf.h"

# define SLEEP 0
# define FORK 1
# define EAT 2
# define THINK 3
# define DEAD 4
# define DONE 5

typedef struct s_jean_paul_sartre
{
	int							id;
	sem_t 						*edit_sem;
	size_t						last_meal_time;
	int							number_of_meals_eaten;
	pthread_t 					death_check_t;
	struct s_data				*my_data;
}	t_nietzsche;

typedef struct s_data
{
	t_nietzsche		*nietzsche;
	pthread_t 		eat_check_t;
	int				how_many_platos;
	size_t			time_to_die;
	size_t			time_to_eat;
	size_t			time_to_sleep;
	int				nums_times_philo_must_eat;
	long			initial_time;
	int				finish;
	sem_t			*chopsticks;
	sem_t			*print_semaphore;
	sem_t			*edit_semaphore;
	sem_t 			*finish_the_program;
	sem_t 			*all_eat_sem;
}	t_data;

/*----------------PETITE_PARSING----------------*/
int				check_arguments(int ac, char **av);
int				parsing(int ac, char **av);
void			initialize_data(t_data *socrates, char **av);

int				death_checker(t_nietzsche *philo);

/*----------------PHILOSOPHY----------------*/
long			ft_get_current_time(void);
// void			create_threads(t_data *socrates);
void 			start_philosophizing(t_nietzsche *philo);
// void			prepare_the_threads(t_nietzsche *my_list);
void			*check_the_philosophers(void *d);
void			prepare_the_processes(t_data *data);
void			take_the_forks_and_eat(t_nietzsche *philo);
void			go_eat(t_nietzsche *philo);
void			go_sleep_think(t_nietzsche *philo);
void			go_think(t_data *data);
void			ft_sleep(int time_in_ms);
void			go_print_b(int b, t_data *data);

/*----------------utils_functions----------------*/
int				ft_atoi(const char *str);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_itoa(int n);
t_nietzsche		*ft_lstnew(int id, void *(*f)(void *), t_data *socrates);
void			ft_lstadd_front(t_nietzsche **lst, t_nietzsche *new);
int				ft_lstsize(t_nietzsche *lst);
t_nietzsche		*ft_lstlast(t_nietzsche *lst);
void			ft_lstadd_back(t_nietzsche **lst, t_nietzsche *new);
void			ft_lstdelone(t_nietzsche *lst, void (*del)(void*));
void			ft_lstclear(t_nietzsche **lst, void (*del)(void*));
void			ft_lstiter(t_nietzsche *lst, void (*f)(void *));

#endif
