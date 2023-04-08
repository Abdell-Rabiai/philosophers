# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: arabiai <arabiai@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/09 14:24:42 by ahmaymou          #+#    #+#              #
#    Updated: 2023/04/08 15:27:39 by arabiai          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

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

ft_utils = $(addprefix ft_utils/, ft_lstadd_back.c ft_lstadd_front.c ft_lstclear.c ft_lstdelone.c ft_lstiter.c ft_lstlast.c ft_lstnew.c ft_lstsize.c ft_atoi.c)

sources = $(addprefix sources/,init_and_parse.c)

SRCS_OBJ = $(sources) $(ft_utils)

SRC = sources/philo_main.c

FLAGS = -Wall -Werror -Wextra -fsanitize=address

HEADER = philo.h

CC = cc

LIBS = ft_printf/libftprintf.a

OBJ = $(SRCS_OBJ:.c=.o)

all : banner2 libftprintf $(NAME)

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
	@printf "$(GREEN) Generating minishell objects... %-33.33s\r" $@
	@$(CC) $(FLAGS) $(READLINE_INC) -c $< -o $@

$(NAME) : $(OBJ) $(SRC) $(HEADER)
	@$(CC) $(FLAGS) $(SRC) $(OBJ) $(LIBS) -o $(NAME)
	@echo "\n\n\t$(Cyan) Enjoooy :)\n $(Color_Off)"

libftprintf :
	@make -C ft_printf/

clean :
	@make clean -C ft_printf
	@rm -rf $(OBJ)

fclean : clean
	@make fclean -C ft_printf
	@rm -rf $(LIBS) $(NAME) $(SRC:.c=.o)
	@rm -rf *.dSYM .vscode

re : fclean all

.PHONY : all clean fclean re
