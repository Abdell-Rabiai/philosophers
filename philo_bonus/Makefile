 # **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/29 12:01:23 by arabiai           #+#    #+#              #
#    Updated: 2023/06/22 15:40:03 by arabiai          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo_bonus

Color_Off=\033[0m
LIGHTRED=\033[1;31m
LightBlue=\033[1;34m
LightPurple=\033[1;35m
Cyan=\033[0;36m
GREEN = \033[92m

BANNER=\
'██████╗  ██╗  ██╗ ██╗ ██╗      ██████╗  ███████╗  ██████╗  ██████╗  ██╗  ██╗ ███████╗ ██████╗  ███████╗'\
'██╔══██╗ ██║  ██║ ██║ ██║     ██╔═══██╗ ██╔════╝ ██╔═══██╗ ██╔══██╗ ██║  ██║ ██╔════╝ ██╔══██╗ ██╔════╝'\
'██████╔╝ ███████║ ██║ ██║     ██║   ██║ ███████╗ ██║   ██║ ██████╔╝ ███████║ █████╗   ██████╔╝ ███████╗'\
'██╔═══╝  ██╔══██║ ██║ ██║     ██║   ██║ ╚════██║ ██║   ██║ ██╔═══╝  ██╔══██║ ██╔══╝   ██╔══██╗ ╚════██║'\
'██║      ██║  ██║ ██║ ███████╗╚██████╔╝ ███████║ ╚██████╔╝ ██║      ██║  ██║ ███████╗ ██║  ██║ ███████║'\
'╚═╝      ╚═╝  ╚═╝ ╚═╝ ╚══════╝ ╚═════╝  ╚══════╝  ╚═════╝  ╚═╝      ╚═╝  ╚═╝ ╚══════╝ ╚═╝  ╚═╝ ╚══════╝'\
'                                                                                             '                                                    

ft_utils = $(addprefix ft_utils/, ft_atoi.c ft_strjoin.c ft_itoa.c)

sources = $(addprefix sources/,init_and_parse_b.c philo_main_utils_b.c philo_main_b.c helper_b.c)

SRCS = $(sources) $(ft_utils)

MAIN_SRC = sources/philo_main.c

FLAGS = -Wall -Werror -Wextra -pthread

HEADER = philo_bonus.h

CC = cc


OBJ = $(SRCS:.c=.o)

all : banner2 $(NAME)

banner2:
	@clear
	@echo "\n"
	@echo "$(LightPurple)"
	@for s in $(BANNER) ; do \
		printf "%s\n" "$$s" ; \
		sleep 0.03 ; \
	done ; \
	echo "$(LIGHTRED)                     By : Abdell-rabiai :) \n$(Color_Off)"

%.o: %.c $(HEADER)
	@printf "$(GREEN) Generating Philosophers objects... %-33.33s\r" $@
	@$(CC) $(FLAGS) $(READLINE_INC) -c $< -o $@

$(NAME) : $(OBJ) $(HEADER)
	@$(CC) $(FLAGS) $(OBJ) -o $(NAME)
	@echo "\n\n\t$(Cyan) Enjoooy :)\n $(Color_Off)"

clean :
	@rm -rf $(OBJ)

fclean : clean
	@rm -rf $(NAME) $(SRCS:.c=.o)
	@rm -rf *.dSYM .vscode

re : fclean all

.PHONY : all clean fclean re
