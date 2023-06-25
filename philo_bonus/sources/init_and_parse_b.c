/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_and_parse_b.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/08 01:48:08 by arabiai           #+#    #+#             */
/*   Updated: 2023/06/25 18:48:32 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo_bonus.h"

void	initialize_data(t_data *socrates, char **av)
{
	socrates->how_many_platos = ft_atoi(av[1]);
	socrates->time_to_die = ft_atoi(av[2]);
	socrates->time_to_eat = ft_atoi(av[3]);
	socrates->time_to_sleep = ft_atoi(av[4]);
	if (av[5])
		socrates->nums_times_philo_must_eat = ft_atoi(av[5]);
	else
		socrates->nums_times_philo_must_eat = -1;
	socrates->finish = 0;
	socrates->nietzsche = malloc(sizeof(t_nietzsche)
			* socrates->how_many_platos);
}

int	check_if_intger(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if ((str[i] == '-' || str[i] == '+') && i == 0)
		{
			i++;
			continue ;
		}
		if (str[i] < '0' || str[i] > '9')
			return (1);
		i++;
	}
	return (0);
}

int	check_arguments(int ac, char **av)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (check_if_intger(av[i]))
		{
			printf("\001\033[1;31m\002Error: Wrong argument type\n\033[0m");
			return (1);
		}
		if (ft_atoi(av[i]) <= 0)
		{
			printf("\001\033[1;31m\002Error: Wrong argument value\n\033[0m");
			return (1);
		}
		i++;
	}
	return (0);
}

int	parsing(int ac, char **av)
{
	if (ac != 5 && ac != 6)
	{
		printf("\001\033[1;31m\002Error: Wrong number of arguments\n\033[0m");
		return (1);
	}
	else if (check_arguments(ac, av))
		return (1);
	return (0);
}

long	ft_get_current_time(void)
{
	long			time_in_seconds;
	struct timeval	time;

	gettimeofday(&time, NULL);
	time_in_seconds = (time.tv_sec * 1000) + (time.tv_usec / 1000);
	return (time_in_seconds);
}
