/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:42:51 by arabiai           #+#    #+#             */
/*   Updated: 2023/04/08 14:06:38 by arabiai          ###   ########.fr       */
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
# include "ft_printf/ft_printf.h"
# include "ft_utils/libft.h"
# include <pthread.h>

typedef struct s_data
{
	t_nietzsche			*nietzsche;
	t_nietzsche			*last;
	int 				time_to_die;
	int 				how_many_platos;
	int 				time_to_eat;
	int 				time_to_sleep;
	int 				end_of_program;
	int 				initial_time;
	pthread_mutex_t		print_mutex;
}	t_data;

/*----------------PETITE_PARSING----------------*/
int			check_arguments(int ac, char **av);
int			parsing(int ac, char **av);
void		initialize_data(t_data *socrates, char **av);
/*----------------PHILOSOPHY----------------*/
long long	ft_get_current_time(void);
void		create_threads(t_data *socrates);
#endif
