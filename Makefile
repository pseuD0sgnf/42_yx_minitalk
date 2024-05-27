# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yuxchen <yuxchen@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/04/10 15:56:14 by yuxchen           #+#    #+#              #
#    Updated: 2024/04/11 19:00:45 by yuxchen          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CNAME	= client
SNAME	= server

CC		= gcc

CFLAGS	= -Wall -Werror -Wextra

LDFLAGS	= ./Printf/libftprintf.a ./Libft/libft.a

INCLUDES	= -Iincludes -ILibft/includes -IPrintf/includes

RM		= rm -f

all:		$(CNAME) $(SNAME)

$(CNAME) $(SNAME):	libft.a libftprintf.a
			$(CC) $(CFLAGS) srcs/$@.c $(INCLUDES) $(LDFLAGS) -o $@

libft.a:
			$(MAKE) -C Libft

libftprintf.a:
			$(MAKE) -C Printf

%.o: %.c
			$(CC)  $(INCLUDES) -c $< -o $@

clean:
			$(MAKE) -C Libft clean
			$(MAKE) -C Printf clean
			$(RM) $(OBJS)

fclean:		clean
			$(MAKE) -C Libft fclean
			$(MAKE) -C Printf fclean
			$(RM) $(CNAME) $(SNAME)

re:			fclean all

.PHONY:		all clean fclean re
