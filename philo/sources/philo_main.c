/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_main.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/31 20:39:45 by arabiai           #+#    #+#             */
/*   Updated: 2023/03/31 23:37:31 by arabiai          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void *my_turn(void *arg)
{
	(void)arg;
	while (1)
	{
		printf("i'll take this fork\n");
		sleep(3);
	}
	return (NULL);
}

void* your_turn(void *arg)
{
	(void)arg;
	while (1)
	{
		printf("No, it's mine you idiot\n");
		sleep(2);
	}
	return (NULL);
}

void* third_party(void *arg)
{
	(void)arg;
	while (1)
	{
		printf("Wait a minute, this fork is none of yours yuo fucking idiots\n");
		sleep(2);
	}
	return (NULL);
}

int main()
{
	pthread_t thread1;
	pthread_t thread2;
	pthread_t thread3;

	pthread_create(&thread1, NULL, &my_turn, NULL);
	pthread_create(&thread2, NULL, &your_turn, NULL);
	pthread_create(&thread3, NULL, &third_party, NULL);
	pthread_join(thread1, NULL);
	pthread_join(thread2, NULL);
	pthread_join(thread3, NULL);
}