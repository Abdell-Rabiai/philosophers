/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_parse.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:48:08 by arabiai           #+#    #+#             */
/*   Updated: 2023/04/09 12:44:37 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void initialize_data(t_data *socrates, char **av)
{
	socrates->how_many_platos = ft_atoi(av[1]);
	socrates->time_to_die = ft_atoi(av[2]);
	socrates->time_to_eat = ft_atoi(av[3]);
	socrates->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		socrates->end_of_program = ft_atoi(av[5]);
	else
		socrates->end_of_program = -1;
	socrates->initial_time = ft_get_current_time();
	socrates->nietzsche = NULL;
	if (pthread_mutex_init(&socrates->print_mutex, NULL))
		return ;
}

int check_if_intger(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && i == 0)
		{
			i++;
			continue;
		}
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int check_arguments(int ac, char **av)
{
	int i;

	i = 1;
	while (i < ac)
	{
		if (check_if_intger(av[i]))
		{
			ft_printf(2, "Error: Wrong argument type\n");
			return (1);
		}
		if (ft_atoi(av[i]) <= 0)
		{
			ft_printf(2, "Error: Wrong argument value\n");
			return (1);
		}
		i++;
	}
	return (0);
}

int parsing(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		ft_printf(2, "Error: Wrong number of arguments\n");
		return (1);
	}
	else if (check_arguments(ac, av))
		return (1);
	return (0);
}

long long	ft_get_current_time(void)
{
	long long	time_in_seconds;
	struct timeval time;

	gettimeofday(&time, NULL);
	time_in_seconds = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_in_seconds);
}