# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nreyes-p <nreyes-p@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/03/09 18:56:55 by nreyes-p          #+#    #+#              #
#    Updated: 2023/03/09 19:01:28 by nreyes-p         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
SOURCES = ft_printf.c
OBJECTS = $(SOURCES:.c=.o)
#BONUS_SRC = ft_lstnew.c ft_lstadd_front.c ft_lstsize.c ft_lstlast.c ft_lstadd_back.c ft_lstdelone.c ft_lstclear.c ft_lstiter.c ft_lstmap.c
#BONUS_OBJECTS = $(BONUS_SRC:.c=.o)
FLAGS = -Wall -Werror -Wextra
RM = rm -rf

all: $(NAME)

$(NAME): $(OBJECTS)
	ar rcs $(NAME) $(OBJECTS)

$(OBJECTS):
	gcc $(FLAGS) -c $(SOURCES)

#$(BONUS_OBJECTS):
#	gcc $(FLAGS) -c $(BONUS_SRC)

clean:
	$(RM) $(OBJECTS) $(BONUS_OBJECTS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

#bonus: $(OBJECTS) $(BONUS_OBJECTS)
#	ar rcs $(NAME) $(OBJECTS) $(BONUS_OBJECTS)

.PHONY: all clean fclean re bonus